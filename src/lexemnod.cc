/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#include "debug.h"
#include "lexemnod.h"


int dreiortho(char* s)
{
    int l = strlen(s) ;
    if (l < 3)
        return (0) ;
    if (s[0]==s[1] && s[1] == s[2])
    {
        statistics("Dreiortho Start " << s) ;
        return (1) ;
    }
    if (s[l-1]==s[l-2] && s[l-2] == s[l-3])
    {
        statistics("Dreiortho End " << s) ;
        return (1) ;
    }
    return (0) ;
}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////                                                                                ////
////  class TLexemNode                                                              ////
////                                                                                ////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////
//
//  TLexemNode::TLexemNode (...)
//
//  Eingabe:
//      keine
//  Zweck:
//      Erzeugt einen Knoten fuer einen Zerlegungsbaum. Der Kopf und der Rest dieser
//      Zerlegung bestehen jeweils aus einem leeren Lexem. Das Array, das die
//      Zerlegungen des Rests aufnimmt, ist daher auch noch leer.
//  Seiteneffekte:
//      keine
//  Ausgabe:
//      keine

TLexemNode::TLexemNode () :
    head(),
    rest(),
    #ifdef _Windows
    children(5, 0, 5)
    #else
    children()
    #endif
{
    statistics("Constructor TTLexemNode::TLexemNode() - Empty Node");
}


////////////////////////////////////////////////////////////////////////////////////////
//
//  TLexemNode::TLexemNode (...)
//
//  Eingabe:
//      const TLexem &h
//          Kopf einer Teilzerlegung
//      const TLexem &r
//          Rest einer Teilzerlegung
//  Zweck:
//      Erzeugt einen Knoten fuer einen Zerlegungsbaum. Der Kopf besteht aus dem Lexem
//      ``h'', der Rest aus dem Lexem ``r''. Das Array, das die Zerlegungen des Rests
//      aufnimmt, ist noch leer.
//  Seiteneffekte:
//      keine
//  Ausgabe:
//      keine

TLexemNode::TLexemNode (const TLexem &l1, const TLexem &l2) :
    head(l1),
    rest(l2),
    #ifdef _Windows
    children(5, 0, 5)
    #else
    children()
    #endif
{
    statistics("Constructor TLexemNode::TLexemNode(const TLexem &head = " << l1.Chars() << " - const TLexem &lemma = " << head.Lemma() << " - const TLexem &rest = " << l2.Chars() << ")");
    statistics("Transcription Head " << l1.Transcription()) ;
    if (head.Chars().length() != head.Lemma().length())
        penalty = 3 ;
    else penalty = 2 ;
    if (head.Lemma() == "Praefix")
        penalty = 1 ;
}


////////////////////////////////////////////////////////////////////////////////////////
//
//  TLexemNode::~TLexemNode (...)
//
//  Eingabe:
//      keine
//  Zweck:
//      Loescht einen Knoten eines Zerlegungsbaums und die von ihm ausgehenden Teilbaeume.
//  Seiteneffekte:
//      keine
//  Ausgabe:
//      keine

TLexemNode::~TLexemNode ()
{
    statistics("Applying TLexem::delete() " << head.Chars()) ;
    // alle Unterbaeume des Knotens loeschen
    #ifdef _Windows
    for (unsigned int i = LowerBound(); i < LowerBound() + GetItemsInContainer(); i++)
        delete children[i];
    #else
    for (iterator i = begin(); i < end(); i++)
    {
        statistics("Applying TLexem::delete SubTree " << (*i)->head.Chars()) ;
        delete (*i);
    }
    #endif
}


////////////////////////////////////////////////////////////////////////////////////////
//
//  TLexemNode::is_unwanted (...)
//
//  Eingabe:
//      keine
//  Zweck:
//      Bestimmt, ob ein Teilzerlegungsbaum entfernt werden muß, weil er eine der
//      folgenden Bedingungen erfüllt:
//       -  die Teilzerlegung beginnt mit einem Lemma, das nicht als Teil einer
//      Zerlegung erwünscht ist
//       -  alle Unterbäume mußten entfernt werden
//  Seiteneffekte:
//      löscht möglicherweise Unterbäume
//  Ausgabe:
//      return bool:
//       -  false    der Knoten kann beibehalten werden
//       -  true     der Knoten muß entfernt werden

bool TLexemNode::is_unwanted ()
{
    statistics("Applying TLexem::is_unwanted() for " << Head().Lemma() << " " << Rest().Lemma()) ;
    // steht am Anfang der Zerlegung ein unerwuenschtes Wort?
    if (Head().Lemma() == "er" || Head().Lemma() == "es" || Head().Lemma() == "ich")
    {
        statistics("UNWANTED HEAD") ;
        return true;
    }
    if (Head().Chars() == "be" && !is_empty())
    {
        #ifndef _Windows
        for (iterator i = begin(); i < end(); i++)
        {
            // Ist die ``i''-te Teilzerlegung unerwuenscht?
            if ((*i)->Head().Lemma() == "Praefix")
            {
                statistics("UNWANTED DECOMPOSITION 1 be+Praefix") ;
                delete (*i);
                erase(i--);
            }
        }
        #else
        for (unsigned int i = LowerBound(); i < LowerBound() + GetItemsInContainer(); i++)
        {
            // ist die »ia-te Teilzerlegung unerwünscht?
            if ((children[i]->Head()).Lemma() == "Praefix")
            {
                statistics("UNWANTED DECOMPOSITION be+Praefix") ;
                delete children[i];
                RemoveEntry(i--);
            }
        }
        #endif
        if (is_empty())
        {
            // diese Zerlegung ist unerwuenscht
            return true;
        }
        else
        {
            return false;
        }
    }
    // ist dieser Knoten ein Blatt?
    if (is_empty())
    {
        if (Rest().Lemma() == "er" || Rest().Lemma() == "es" || Rest().Lemma() == "ich")
        {
            statistics("UNWANTED LEAF") ;
            return true;
        }
        statistics("LEAF OK") ;
        return false ;
    }
    // alle Unterbaeume nach unerwuenschten Teilzerlegungen untersuchen
    #ifndef _Windows
    for (iterator i = begin(); i < end(); i++)
    {
        // Ist die ``i''-te Teilzerlegung unerwuenscht?
        if ((*i)->is_unwanted())
        {
            statistics("UNWANTED DECOMPOSITION 2") ;
            delete (*i);
            erase(i--);
        }
    }
    #else
    for (unsigned int i = LowerBound(); i < LowerBound() + GetItemsInContainer(); i++)
    {
        // ist die »ia-te Teilzerlegung unerwünscht?
        if (children[i]->is_unwanted())
        {
            statistics("UNWANTED DECOMPOSITION") ;
            delete children[i];
            RemoveEntry(i--);
        }
    }
    #endif
    // Sind alle Teilzerlegungen entfernt worden?
    if (is_empty())
    {
        // diese Zerlegung ist unerwuenscht
        return true;
    }
    else
    {
        return false;
    }
}


////////////////////////////////////////////////////////////////////////////////////////
//
//  get_best_decomposition (...)
//
//  Eingabe:
//      const TLexemNode &root
//          Teilzerlegungsbaum eines Kompositums
//      int &score
//          Ergebnisvariable
//  Zweck:
//      Sucht aus dem Teilzerlegungsbaum »roota das beste Teilkompositum heraus.
//  Seiteneffekte:
//      keine
//  Ausgabe:
//      return TLexem
//          das Teilkompositum mit der hoechsten Punktzahl in der uebergebenen
//          Teilzerlegung
//      int &score
//          die Punktzahl des zurueckgegebenen Teilkompositums

TLexem get_best_decomposition (TLexemNodePointer root, int &s, int &p)
{
    statistics("Applying TLexem::get_best_decomposition (TLexemNode *root = {\"" << root->Head().Chars() << "\", \"" << root->Rest().Chars() <<"\"})");

    int s1, s3;
    // ist das hier ein Blatt?
    if (root->is_empty())
    {
        // gib die hier gespeicherte Zerlegung (bestehend aus zwei Lexemen) zurueck
        s1 = root->Head().Chars().length();
        s3 = root->Rest().Chars().length();
        root->penalty += 2 ;
        p = root->penalty ;
        s = s1 * s1 + s3 * s3;
        if (dreiortho((char*)root->Head().Chars().c_str()) == 1 || dreiortho((char*)root->Rest().Chars().c_str()) == 1)
        {
            root->penalty += 5 ;
            p = root->penalty ;
        }
        statistics("Decomposition Leaf (TLexemNode *root = {\"" << root->Head().Chars() << "\", \"" << root->Rest().Chars() <<"\"})" << " Score " << s << " Penalty " << p) ;
        statistics("Transcription " << root->Head().Transcription() << " + " << root->Rest().Transcription()) ;
        return root->Head() + root->Rest();
    }
    // die beste Teilzerlegung aus den Unterbaeumen suchen
    statistics("No Leaf for " << root->Head().Chars()) ;
    int best_score = -32000, res_score;
    int pen, bestpen=0 ;
    TLexem best_lexem, res_lexem;
    #ifndef _Windows
    for (TLexemNode::const_iterator i = root->begin(); i < root->end(); i++)
    {
        statistics("Searching Subtree, Current item " << (*i)->Head().Chars()) ;
        res_lexem = get_best_decomposition(*i, res_score, pen);
        res_score -= pen * 100 ;
        statistics("Score Obtained " << res_score << " Current Best " << best_score) ;
        if (res_score > best_score)
        {
            statistics("New Best Score") ;
            best_score = res_score;
            best_lexem = res_lexem;
            bestpen = pen ;
        }
    }
    #else
    for (unsigned int i = root->LowerBound(); i < root->LowerBound() + root->GetItemsInContainer(); i++)
    {
        res_lexem = get_best_decomposition(root->Children(i), res_score, pen);
        res_score -= pen*100 ;
        statistics("Score Obtained " << res_score << " Current Best " << best_score) ;
        if (res_score > best_score)
        {
            statistics("New Best Score") ;
            best_score = res_score ;
            bestpen = pen ;
            best_lexem = res_lexem;
        }
    }
    #endif
    // gib die beste Zerlegung zurueck
    s1 = root->Head().Lemma().length();
    s = s1 * s1 + (best_score + bestpen*100);
    root->penalty += bestpen ;
    p = root->penalty ;
    statistics("Result TLexem::get_best_decomposition Score " << s << " Penalty " << p << " for TLexemNode *root = {\"" << root->Head().Chars() << " " << best_lexem.Chars() << " " << "\"})") ;

    return root->Head() + best_lexem;
}

