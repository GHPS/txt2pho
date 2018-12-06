/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#include <iostream>

#include "debug.h"
#include "ipa.h"
#include "lexem.h"
extern FILE* errfile ;

#define cremove(s,i)   {unsigned int j ; for (j=(i) ; j < (s).length()-1 ; j++) (s)[j] = (s)[j+1] ; s[j] = '\0' ; }


////////////////////////////////////////////////////////////////////////////////////////

TLexem::TLexem ()
{
    wordClasses = NULL ;
    cntWordClasses = 0 ;
    flexrul = "" ;
    type = nothing ;
    SetWordClass(Unknown);
    setType();
}


////////////////////////////////////////////////////////////////////////////////////////

TLexem::TLexem (const string &s) :
    chars(s),
    wordClasses(NULL),
    cntWordClasses(0),
    type(nothing),
    flexrul("")
{
    statistics("TLexem::TLexem: Laenge == " << s.length());
    SetWordClass(Unknown);
    setType();
    statistics("TLexem::TLexem: Laenge == " << s.length());
}


////////////////////////////////////////////////////////////////////////////////////////

TLexem::~TLexem ()
{
    delete[] wordClasses;
}


////////////////////////////////////////////////////////////////////////////////////////
//
//  TLexem::operator+= (...)
//
//  Eingabe:
//      const TLexem &l
//          ein transkribiertes Lexem
//  Zweck:
//      VerknNpft das Urpsrungslexem mit dem transkribiertem Lexem »la.
//  Seiteneffekte:
//      keine
//  Ausgabe:
//    Eine Referenz auf sich selbst.

TLexem &TLexem::operator+= (const TLexem &l)
{
    // ???: Ist die Annahme korrekt?
    assert(l.Type() == wordform);
    if (Type() != wordform)
    {
        *this = l;
        return *this;
    }
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // die Orthographie des Lexems »la an die ursprNngliche Orthographie anh?ngen
    chars += l.Chars();
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // die Transkription des Lexems »la an die ursprNngliche Transkription anh?ngen
    // F?ngt das anzuh?ngende Lexem mit einem (betonten oder unbetonten) Vokal an?
    if (is_ipa_vowel(l.Transcription(0)) ||
            is_ipa_vowel(l.Transcription(1)) && is_ipa_stress(l.Transcription(0)))
    {
        if (is_ipa_stress(l.Transcription(0)))
        {
            transcription += l.Transcription(0);
            transcription += ipa_glottal_stop;
            transcription += l.Transcription(1, l.Transcription().length() - 1);
        }
        else
        {
            transcription += ipa_glottal_stop;
            transcription += l.Transcription();
        }
    }
    else
        transcription += l.Transcription();
    // alle Hauptbetonungen außer der ersten zu Nebenbetonungen abschw?chen
    size_t pos = transcription.find(ipa_primary_stress);
    #ifdef Windows
    if (pos != NPOS)
    #else
    if (pos != string::npos)
    #endif
    {
        pos++;
        #ifdef Windows
        while ((pos = transcription.find(ipa_primary_stress, pos)) != NPOS)
        #else
        while ((pos = transcription.find(ipa_primary_stress, pos)) != string::npos)
        #endif
            transcription[pos] = ipa_secondary_stress;
    }
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // die dazugehörigen Lemmata verknNpfen
    lemma = Lemma() + " + " + l.Lemma();
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // die resultierende Wortklasse eintragen
    flexrul = l.flexrul ;
    SetWordClasses(l.WordClassesCount(), l.WordClasses());
    return *this;
}


////////////////////////////////////////////////////////////////////////////////////////

TLexem operator+ (const TLexem &l1, const TLexem &l2)
{
    TLexem result = l1;
    result += l2;
    return result;
}



////////////////////////////////////////////////////////////////////////////////////////

void TLexem::setType ()
{
    if (chars.length() == 0)
        type = nothing;
    else if (chars[0] == '{' && chars[chars.length() - 1] == '}')
        type = comment;
    else if (Chars().length() > 2 && Chars(chars.length() - 2, 2) == "##")
        type = control;
    else if (chars == ",")
        type = comma;
    else if (chars == ".")
        type = point;
    else if (chars == ":")
        type = colon;
    else if (chars == ";")
        type = semicolon;
    else if (chars == "!")
        type = exclamation;
    else if (chars == "?")
        type = question;
    else if (chars == "-")
        type = dash;
    else type = wordform;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TLexem::starts_with_one_of (const string &charset) const
{
    return chars.find_first_of(charset) == 0;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TLexem::contains_only (const string &charset) const
{
    #ifdef Windows
    return chars.find_first_not_of(charset) == NPOS;
    #else
    return chars.find_first_not_of(charset) == string::npos;
    #endif
}


////////////////////////////////////////////////////////////////////////////////////////
//
//  TLexem::is_valid_word (...)
//
//  Eingabe:
//      keine
//  Zweck:
//      ÜberprNft, ob das Lexem formal ein Wort sein kann.
//  Seiteneffekte:
//      keine
//  Ausgabe:
//      return bool:
//       -  false    das Lexem kann aus formalen GrNnden kein Wort sein
//       -  true     sonst

bool TLexem::is_valid_word () const
{
    if (chars.length() < 2)
        return false;
    bool valid_start[cnt_chars_in_alphabet][cnt_chars_in_alphabet] =
#include "valstart.inc"
        if (chars[0] == asc_sz_lig)
            return false;
    char ch0 = ucase(chars[0]), ch1 = ucase(chars[1]);
    if (ch0 >= 'A' && ch0 <= 'Z' && ch1 >= 'A' && ch1 <= 'Z')
        return valid_start[ch0 - 'A'][ch1 - 'A'];
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TLexem::has_word_class (TWordClass wcl) const
{
    if ((wcl == Unknown) || (cntWordClasses == 1 && wordClasses[0] == Unknown))
        return true;
    for (short i = 0; i < cntWordClasses; i++)
        if (wordClasses[i] == wcl)
            return true;
    return false;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TLexem::has_ending (const TFlexion::TRule &rule) const
{
    if (rule.orth_flex.length() >= chars.length())
        return false;
    for (size_t i = 0, j = chars.length() - 1; i < rule.orth_flex.length(); i++, j--)
        if (rule.orth_flex[i] != chars[j])
            return false;
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////

void TLexem::SetWordClass (TWordClass wcl)
{
    SetWordClasses(1, &wcl);
}


////////////////////////////////////////////////////////////////////////////////////////
int TLexem::EmailChange()
{
    int i ;
    int done = 0 ;
    int email = 1 ;
    for (i = strlen(chars.c_str()) - 2; i > -1 ; i--)
    {
        if (chars[i] == 'o' && chars[i+1] == 'e' && email == 1)
        {
            chars[i] = 'ö' ;
            cremove(chars, i+1) ;
            statistics("EMAIL CHANGE oe " << chars) ;
            done = 1 ;
        }
        if (chars[i] == 'a' && chars[i+1] == 'e' && email == 1)
        {
            chars[i] = 'ä' ;
            cremove(chars, i+1) ;
            statistics("EMAIL CHANGE ae " << chars) ;
            done = 1 ;
        }
        if (chars[i] == 'u' && chars[i+1] == 'e' && email == 1)
        {
            chars[i] = 'ü' ;
            cremove(chars, i+1) ;
            statistics("EMAIL CHANGE ue " << chars) ;
            done = 1 ;
        }
        if (chars[i] == 'O' && chars[i+1] == 'e' && email == 1)
        {
            chars[i] = 'Ö' ;
            cremove(chars, i+1) ;
            statistics("EMAIL CHANGE Oe " << chars) ;
            done = 1 ;
        }
        if (chars[i] == 'A' && chars[i+1] == 'e' && email == 1)
        {
            chars[i] = 'Ä' ;
            cremove(chars, i+1) ;
            statistics("EMAIL CHANGE Ae " << chars) ;
            done = 1 ;
        }
        if (chars[i] == 'U' && chars[i+1] == 'e' && email == 1)
        {
            chars[i] = 'Ü' ;
            cremove(chars, i+1) ;
            statistics("EMAIL CHANGE Ue " << chars) ;
            done = 1 ;
        }
    }
    return (done) ;
}

int TLexem::SetUmlaut (int email)
{
    int done = 0 ;
    int i ;
    if (email)
        EmailChange() ;
    statistics("In SET UMLAUT " << email << " " << Chars()) ;
    for (i = strlen(chars.c_str()) - 2; i > -1 ; i--)
    {
        if (chars[i] == asc_o_umlaut)
        {
            chars[i] = 'o' ;
            done = 1 ;
            break ;
        }
        if (chars[i] == asc_a_umlaut)
        {
            chars[i] = 'a' ;
            done = 1 ;
            break ;
        }
        if (chars[i] == asc_u_umlaut)
        {
            chars[i] = 'u' ;
            done = 1 ;
            break ;
        }
        if (chars[i] == asc_O_umlaut)
        {
            chars[i] = 'O' ;
            done = 1 ;
            break ;
        }
        if (chars[i] == asc_A_umlaut)
        {
            chars[i] = 'A' ;
            done = 1 ;
            break ;
        }
        if (chars[i] == asc_U_umlaut)
        {
            chars[i] = 'U' ;
            done = 1 ;
            break ;
        }
    }
    statistics("nach SET UMLAUT " << Chars()) ;
    return (done) ;
}

void TLexem::SetUmlautPhon ()
{
    statistics("in  SET UMLAUT PHON " << Transcription()) ;
    int i ;
    int umlaut_found = 0 ;
    int maxone =  strlen(transcription.c_str()) - 1 ;
    for (i = maxone ; i > -1 ; i--)
    {
        if (transcription[i] == 'o')
        {
            transcription[i] = '2' ;
            umlaut_found = 1 ;
            break ;
        }
        if (transcription[i] == 'O' && i < maxone && transcription[i+1] != 'Y')
        {
            transcription[i] = '9' ;
            umlaut_found = 1 ;
            break ;
        }
        if (transcription[i] == 'a' && i < maxone && transcription[i+1] != 'I' && transcription[i+1] != 'U')
        {
            transcription[i] = 'E' ;
            umlaut_found = 1 ;
            break ;
        }
        if (transcription[i] == 'u')
        {
            transcription[i] = 'y' ;
            umlaut_found = 1 ;
            break ;
        }
        if (transcription[i] == 'U' && i > 0 && transcription[i-1] == 'a')
        {
            transcription[i] = 'Y' ;
            transcription[i-1] = 'O' ;
            umlaut_found = 1 ;
            break ;
        }
        if (transcription[i] == 'U')
        {
            transcription[i] = 'Y' ;
            umlaut_found = 1 ;
            break ;
        }
    }
    if (i < (int)strlen(transcription.c_str())-1)
        if (umlaut_found)
        {
            if (transcription[i+1] == 'x')
                transcription[i+1] = 'C' ;
            if (i < (int)strlen(transcription.c_str())-2)
                if (transcription[i+2] == 'x' && strchr("::", transcription[i+1]) != NULL)
                    transcription[i+2] = 'C' ;
        }
    statistics("nach  SET UMLAUT PHON " << Transcription()) ;
}


////////////////////////////////////////////////////////////////////////////////////////

void TLexem::SetWordClasses (short cnt_wcls, const TWordClass* wcls)
{
    if (wordClasses != NULL)
    {
        delete[] wordClasses;
    }
    wordClasses = new TWordClass[cntWordClasses = cnt_wcls];
    for (short i = 0; i < cntWordClasses; i++)
        wordClasses[i] = wcls[i];
}


////////////////////////////////////////////////////////////////////////////////////////

void TLexem::init (const TLexem &l)
{
    if (this == &l)
        return;
    flexrul = l.flexrul ;
    chars = l.Chars();
    transcription = l.Transcription();
    lemma = l.Lemma();
    SetWordClasses(l.WordClassesCount(), l.WordClasses());
    setType();
}


////////////////////////////////////////////////////////////////////////////////////////

void fread_lexem (FILE* infile, TLexem &lexem)
{
    statistics("fread_lexem betreten");
    char buffer[1024];
    buffer[0] = '\0';
    if (!feof(infile))
        fscanf(infile, "%s", buffer);
    lexem = TLexem((char*)buffer);
    statistics("in fread_lexem");
    statistics("fread_lexem: " << lexem.Chars());
}


////////////////////////////////////////////////////////////////////////////////////////

void fwrite_lexem (FILE* outfile, const TLexem &lexem)
{
    if (lexem.Type() == TLexem::wordform || lexem.Type() == TLexem::control)
    {
        string str = wcl2str(lexem.WordClassesCount(), lexem.WordClasses());
        statistics("Hallo") ;
        statistics(lexem.Transcription()) ;
        statistics(str) ;
        fprintf(outfile, "%s %s X LEX%s (%s) [%s]\n", lexem.Transcription().c_str(), str.c_str(), lexem.Chars().c_str(), lexem.Lemma().c_str(), lexem.flexrul.c_str());
        /*		if (lexem.flexrul != NULL) {
            fprintf(outfile,"\n") ; }
            else
            fprintf(outfile," [%s %s %s %s]\n",lexem.flexrul->orth_flex.c_str(),lexem.flexrul->orth_base.c_str(),lexem.flexrul->phon_base.c_str(),lexem.flexrul->phon_flex.c_str()) ;
        */
        fflush(outfile) ;
    }
    else
    {
        statistics("Keine Wortform");
        fprintf(outfile, "%s\n", lexem.Chars().c_str());
        fflush(outfile) ;
    }
    statistics("fwrite_lexem: " << lexem.Chars());
}


void put_lexem (char** lexlist, int lexnr, const TLexem &lexem)
{
    int approx_len = lexem.Transcription().length() + lexem.Chars().length() + 12 ;
    if (lexem.Type() != TLexem::wordform && lexem.Type() != TLexem::control)
        approx_len = lexem.Chars().length() + 4 ;
    string str ;
    if (lexem.Type() == TLexem::wordform || lexem.Type() == TLexem::control)
    {
        str = wcl2str(lexem.WordClassesCount(), lexem.WordClasses());
        approx_len += strlen(str.c_str()) ;
    }
//	fprintf(errfile,"APPROX_LEN %d %s %s %s\n",approx_len,lexem.Transcription().c_str(),lexem.Chars().c_str(),str.c_str()) ;
    fflush(errfile) ;
    lexlist[lexnr-1] = (char*)malloc(approx_len) ;
    if (lexem.Type() == TLexem::wordform || lexem.Type() == TLexem::control)
    {
        strcpy(lexlist[lexnr-1], lexem.Transcription().c_str()) ;
        strcat(lexlist[lexnr-1], " ") ;
        strcat(lexlist[lexnr-1], str.c_str()) ;
        strcat(lexlist[lexnr-1], " LEX") ;
        strcat(lexlist[lexnr-1], lexem.Chars().c_str()) ;
        if (strstr(lexem.Chars().c_str(), "##") != NULL)
            strcat(lexlist[lexnr-1], " ##") ;
    }
    else
        strcpy(lexlist[lexnr-1], lexem.Chars().c_str()) ;
//   fprintf(errfile,"ACTUALLY %d\n",strlen(lexlist[lexnr-1])) ;
    fflush(errfile) ;
    statistics("put_lexem: " << lexem.Chars());
}
////////////////////////////////////////////////////////////////////////////////////////

int operator== (const TLexem &l1, const TLexem &l2)
{
    if (&l1 == &l2)
        return 1;
    else
        return l1.Chars() == l2.Chars();
}


////////////////////////////////////////////////////////////////////////////////////////

istream &operator>> (istream &is, TLexem &lexem)
{
    string buffer;
    string lex;
    is >> buffer;
    lex = buffer;
    if (buffer.length() != 0 && buffer[0] == '{')
    {
        do
        {
            is >> buffer;
            lex += " ";
            lex += buffer;
        }   while (buffer[buffer.length() - 1] != '}');
    }
    lexem = TLexem(lex);
    return is;
}


////////////////////////////////////////////////////////////////////////////////////////

ostream &operator<< (ostream &os, const TLexem &lexem)
{
    if (lexem.Type() == TLexem::wordform)
    {
        string str = wcl2str(lexem.WordClassesCount(), lexem.WordClasses());
        os << lexem.Transcription() << " " << str << " X LEX" << lexem.Chars() << "(" << lexem.Lemma() << ")\n";
    }
    else
        os << lexem.Chars() << '\n';
    return os;
}

