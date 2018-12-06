/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#ifdef Windows
    #include <stdio.h>
#else
    #include <stdio.h>
    #include <stdlib.h>
#endif


#include "debug.h"
#include "flexion.h"

#undef SUN
extern short bt2(short) ;

string reverse (const string &s)
{
    string d;
    for (int i = s.length() - 1; i >= 0; i--)
        d += s[i];
    return d;
}



////////////////////////////////////////////////////////////////////////////////////////

TFlexion::TRule::TRule (const string &of, const string &ob, const string &pb, const string &pf, const string &mu, TWordClass p_f, const string &p_t)
{
    // »orth_flexa wird umgekehrt gespeichert
    if (of != "*")
        orth_flex = reverse(of);
    else
        orth_flex = "";
    if (ob != "*")
        orth_base = ob;
    else
        orth_base = "";
    if (pb != "*")
        phon_base = pb;
    else
        phon_base = "";
    if (pf != "*")
        phon_flex = pf;
    else
        phon_flex = "";
    if (mu == "+")
        may_umlaut = true;
    else if (mu == "-")
        may_umlaut = false;
    else
        ERRMSG("Falsche Angabe fNr <may_umlaut>");
    promote_from = p_f;
    promote_to = str2wcl(p_t.c_str());
    if (promote_to == Unknown || promote_to == Error)
        ERRMSG("Falsche Angabe fNr <promote_to>");
}


////////////////////////////////////////////////////////////////////////////////////////

// !!! ACHTUNG !!!  Ver?ndert »mema!

TFlexion::TRule::TRule (const char* &mem)
{
    orth_flex = mem;
//	mem += orth_flex.length() + 1;
    while (*mem++ != '\0')
        ;
    orth_base = mem;
//	mem += orth_base.length() + 1;
    while (*mem++ != '\0')
        ;
    phon_base = mem;
//	mem += phon_base.length() + 1;
    while (*mem++ != '\0')
        ;
    phon_flex = mem;
//	mem += phon_flex.length() + 1;
    while (*mem++ != '\0')	;
    short dummy ;
    memcpy(&dummy, mem, 2) ;
    #ifdef SUN
    dummy = bt2(dummy) ;
    #endif
    may_umlaut = dummy ;
    mem +=2 ;
    memcpy(&dummy, mem, 2) ;
    #ifdef SUN
    dummy = bt2(dummy) ;
    #endif
    promote_from = (TWordClass)dummy ;
    mem +=2 ;
    memcpy(&dummy, mem, 2) ;
    #ifdef SUN
    dummy = bt2(dummy) ;
    #endif
    promote_to = (TWordClass)dummy ;
    mem +=2 ;
}


////////////////////////////////////////////////////////////////////////////////////////

TFlexion::TRule::~TRule ()
{
}


////////////////////////////////////////////////////////////////////////////////////////

void TFlexion::TRule::init (const TFlexion::TRule &rule)
{
    if (this == &rule)
        return;
    orth_flex = rule.orth_flex;
    orth_base = rule.orth_base;
    phon_base = rule.phon_base;
    phon_flex = rule.phon_flex;
    may_umlaut = rule.may_umlaut;
    promote_from = rule.promote_from;
    promote_to = rule.promote_to;
}


////////////////////////////////////////////////////////////////////////////////////////

int _USERENTRY TFlexion::TRule::compare (const void* cvpa, const void* cvpb)
{
    const TFlexion::TRule* a = static_cast<const TFlexion::TRule*>(cvpa);
    const TFlexion::TRule* b = static_cast<const TFlexion::TRule*>(cvpb);
    int alen = a->orth_flex.length(), blen = b->orth_flex.length(), result;
    if (alen == 0)
    {
        if (blen == 0)
            result = 0;
        else
            result = -1;
    }
    else
    {
        if (blen == 0)
            result = 1;
        else
            result = a->orth_flex[0] - b->orth_flex[0];
    }
    if (result == 0)
    {
        if (a->orth_flex == b->orth_flex)
            result = 0;
        else if (a->orth_flex.find(b->orth_flex) == 0)
            result = -1;
        else if (b->orth_flex.find(a->orth_flex) == 0)
            result = 1;
        else
            result = a->orth_flex.compare(b->orth_flex);
    }
    if (result == 0)
        result = a->may_umlaut - b->may_umlaut;
    if (result == 0)
        result = a->promote_from - b->promote_from;
    if (result == 0)
        result = a->promote_to - b->promote_to;
    return result;
}


////////////////////////////////////////////////////////////////////////////////////////

int _USERENTRY TFlexion::TRule::compare_ptr (const void* cvpa, const void* cvpb)
{
    const TFlexion::TRule* const* a = static_cast<const TFlexion::TRule* const*>(cvpa);
    const TFlexion::TRule* const* b = static_cast<const TFlexion::TRule* const*>(cvpb);
    return compare(*a, *b);
}


////////////////////////////////////////////////////////////////////////////////////////

TFlexion::TFlexion (const string &datapath, const string &basename) :
    rules(NULL),
    idx_rules(NULL),
    cnt_rules(NULL),
    cnt_lines(0)
{
    #if defined(IKP_VERSION)
    const TFile sourcefile(datapath + basename + ".flx");
    TFile binaryfile(datapath + basename + ".scf");
    statistics("Load flexion") ;
    if (!binaryfile.Exists())
        if (sourcefile.Exists())
            Compile(sourcefile, binaryfile);
        else
            ERRMSG("Konnte weder '" << sourcefile.Filename() << "' noch '" << binaryfile.Filename() << "' finden");
    else if (sourcefile.Exists() && sourcefile.ModifyTime() > binaryfile.ModifyTime())
        Compile(sourcefile, binaryfile);
    #else
    const TFile binaryfile(datapath + basename + ".scf");
    #endif
    if (!Load(binaryfile))
        ERRMSG("Konnte '" << binaryfile.Filename() << "' nicht laden");
    statistics("Flexion loaded") ;
}


////////////////////////////////////////////////////////////////////////////////////////

TFlexion::~TFlexion ()
{
    // alle Regeln entfernen
    delete[] idx_rules ;
    delete[] cnt_rules ;
    delete[] rules;
}


////////////////////////////////////////////////////////////////////////////////////////

int TFlexion::GetLine (const TFile &sourcefile, string &s1, string &s2, string &s3, string &s4, string &s5, string &s6)
{
    char buffer[568];
    char s1_[81], s2_[81], s3_[81], s4_[81], s5_[81], s6_[81], s7_[81];
    int cnt;
    do
    {
        do
        {
            if (sourcefile.GetS(buffer, sizeof(buffer)) == NULL)
                return EOF;
        } while (strlen(buffer) < 3) ;
        cnt_lines++;
        if (strlen(buffer) > 10 && buffer[strlen(buffer) - 1] != 0x0d && buffer[strlen(buffer)-1] != 0x0a)
            WARNMSG("(" << sourcefile.Filename() << " | " << cnt_lines << "): Zeile zu lang");
        char* comment = strstr(buffer, "//");
        if (comment != NULL)
            *comment = '\0';
        cnt = sscanf(buffer, "%80s %80s %80s %80s %80s %80s %80s", s1_, s2_, s3_, s4_, s5_, s6_, s7_);
//		fprintf(errfile,"%s nach %s %s %s %s %s %s %s\n",buffer,s1_,s2_,s3_,s4_,s5_,s6_,s7_) ;
    }	while (cnt == EOF);
    s1 = s1_;
    s2 = s2_;
    s3 = s3_;
    s4 = s4_;
    s5 = s5_;
    s6 = s6_;
    return cnt;
}


////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////
//
//  TFlexion::Compile (...)
//
//  Eingabe:
//      const TFile &sourcefile
//          eine Textdatei mit Flexionsregeln
//      TFile &binaryfile
//          die Datei, in die die Ausgabe geschrieben werden soll
//  Zweck:
//      Erstellt aus einer Eingabedatei im ASCII-Zeichensatz (bzw. IPA-Zeichensatz fNr
//      die Transkriptionen) eine komprimierte Datei in einem Bin?rformat. Das Format
//      eines Blocks in der Eingabe sieht wie folgt aus:
//
//      FLEXION <wordClass>
//        :
//      <orth_flex> <orth_base> <phon_base> <phon_flex> <umlaut> <promote_to>
//        :
//      ENDE
//
//      Es können beliebig viele dieser Blöcke in der Eingabe angegeben werden. In der
//      Datei können Kommentare stehen, die mit "//" beginnen und mit dem Ende der
//      jeweiligen Zeile aufhören (also wie in C++). Leerzeilen sind ebenso erlaubt.
//      Die Wörter "FLEXION" und "ENDE" sind SchlNsselwörter, die den Anfang bzw. das
//      Ende eines Regelblocks markieren. Alle Regeln, die innerhalb dieses Blocks
//      aufgefNhrt werden, werden nur auf Wörter angewandt, deren Wortklasse mit der
//      hinter "FLEXION" angegebenen Nbereinstimmt. FNr <wordClass> sind die im
//      Aufz?hlungstyp TWordClass (s. "wrdclass.h") definierten Werte zul?ssig.
//      Hier nun die Bedeutung der einzelnen Felder in jeder Zeile:
//          <orth_flex>     eine mögliche lexikalische Wortendung
//          <orth_base>     die lexikalische Endung der zugehörigen Grundform
//          <phon_base>     die phonetische Endung der Grundform
//          <phon_flex>     die Aussprache der flektierten Wortendung
//          <may_umlaut>    Angabe, ob diese Regel einen Umlaut bewirkt ("+" oder "-")
//          <promote_to>    die Wortklasse, die sich nach Anwendung dieser Regel ergibt
//      FNr eine Null-Endung ist das Zeichen "*" einzutragen.
//
//      Die Funktion Nbersetzt das in
//        - eine Tabelle mit Anzahl der Regeln pro Endbuchstabe
//        - eine Liste der Regeln mit jeweils
//            - vier nullterminierten Zeichenketten fNr die Endungen
//            - einem Bin?rwert fNr <umlaut>
//            - einem Bin?rwert fNr die Ausgangswortklasse
//            - einem Bin?rwert fNr die Zielwortklasse

bool TFlexion::Compile (const TFile &sourcefile, TFile &binaryfile)
{
    TWordClass wcl;
    int cnt;
    TRule** rules = NULL;
    short size = 0;
    short used = 0;
    short i ;
    statistics("Compiling Flexion List") ;
    if (!sourcefile.Open('b'))
        ERRMSG("(" << sourcefile.Filename() << "): Datei konnte nicht geöffnet werden");
    // bis zum Ende der Datei lesen
    while ((cnt = GetLine(sourcefile, tok1, tok2, tok3, tok4, tok5, tok6)) != EOF)
    {
        // F?ngt diese Zeile nicht mit dem Wort "FLEXION" an?
        if (tok1 != "FLEXION")
            ERRMSG("(" << sourcefile.Filename() << ", " << cnt_lines << "): SchlNsselwort 'FLEXION' nicht gefunden");
        // Ist "FLEXION" das einzige Wort in dieser Zeile?
        if (cnt == 1)
            ERRMSG("(" << sourcefile.Filename() << ", " << cnt_lines << "): Keine Wortartenangabe nach 'FLEXION'");
        // Gibt es mehr als einen Parameter fNr die Wortart?
        if (cnt != 2)
            ERRMSG("(" << sourcefile.Filename() << ", " << cnt_lines << "): Zuviele Angaben nach 'FLEXION'");
        wcl = str2wcl(tok2);
        // Wurde eine ungNltige Wortart angegeben?
        if (wcl >= NumberOfWordClasses)
            ERRMSG("(" << sourcefile.Filename() << ", " << cnt_lines << "): Fehlerhafte Wortartenangabe");
        // eine korrekte Flexionsregel besteht aus fNnf bzw. sechs Feldern
        while ((cnt = GetLine(sourcefile, tok1, tok2, tok3, tok4, tok5, tok6)) == 5 || cnt == 6)
        {
            // Ist der bereits angeforderte Speicher schon aufgebraucht?
            if (used == size)
            {
                // Speicher fNr 50 weitere Verweise auf Flexionsregeln anfordern, ...
                TRule** temp = NULL;
                #ifdef _Windows
                try
                {
                #endif
                    temp = new TRule *[size += 50];
                    #ifdef _Windows
                    #if defined(__GNUC__)
                    if (temp == NULL)
                        throw bad_alloc();
                    #endif
                }
                catch (xalloc)
                    #else
                    if (temp == NULL)
                    #endif
                {
                    binaryfile.Close();
                    for (i = 0; i < used; i++)
                        delete rules[i];
                    delete[] rules;
                    ERRMSG("Speicheranforderung fNr Zeiger 'temp' fehlgeschlagen");
                }
                // ... die alten Verweise auf Regeln umkopieren, ...
                for (i = 0; i < used; i++)
                    temp[i] = rules[i];
                // ... neue Verweise mit NULL initialisieren ...
                for (i = used; i < size; i++)
                    temp[i] = NULL;
                // und den alten Speicher wieder freigeben.
                delete[] rules;
                rules = temp;
            }
            // Fehlt das (optionale) sechste Feld?
            if (cnt == 5)
            {
                // bei dieser Regel soll die Ausgangswortart beibehalten werden.
                tok6 = wcl2str(wcl);
            }
            // Regel in die Tabelle aufnehmen
            #ifdef Windows
            try
            {
            #endif
                rules[used] = new TRule(tok1, tok2, tok3, tok4, tok5, wcl, tok6);
                #if defined(__GNUC__)
//					if (rules[used] == NULL)
//						throw bad_alloc();
                #endif
                #ifndef Windows
                if (rules[used] == NULL)
                #else
            }
            catch (xalloc)
                #endif
                {
                    binaryfile.Close();
                    for (i = 0; i < used; i++)
                        delete rules[i];
                    delete[] rules;
                    ERRMSG("Speicheranforderung fNr neue Regel fehlgeschlagen");
                }
//				fprintf(errfile,"%s - %s - %s - %s - %d - %d -  %d\n",rules[used]->orth_flex.c_str(),rules[used]->orth_base.c_str(),rules[used]->phon_base.c_str(),rules[used]->phon_flex.c_str(),rules[used]->may_umlaut,rules[used]->promote_from,rules[used]->promote_to) ;
                used++;
            }
            // Wieso wurde das Lesen des vorherigen Regelblocks abgebrochen?
            switch (cnt)
            {
                // die Datei wurde vollst?ndig bearbeitet ==> FEHLER!
                case EOF:
                    ERRMSG("(" << sourcefile.Filename() << ", " << cnt_lines << "): Unerwartetes Dateiende");
                    break;
                // die Zeile bestand aus weniger als fNnf Feldern ==> FEHLER!
                case 2:
                case 3:
                case 4:
                // die Zeile bestand aus mehr als sechs Feldern ==> FEHLER!
                case 7:
                    ERRMSG("(" << sourcefile.Filename() << ", " << cnt_lines << "): UngNltiges Zeilenformat");
                    break;
            }
            // Lautet das einzige Wort auf dieser Zeile nicht "ENDE"?
            if (cnt == 1 && tok1 != "ENDE")
                ERRMSG("(" << sourcefile.Filename() << ", " << cnt_lines << "): SchlNsselwort 'ENDE' nicht gefunden");
        }
        if (!sourcefile.Close())
            WARNMSG("(" << sourcefile.Filename() << "): Datei konnte nicht geschlossen werden");
        // Die Regeln sortieren
        statistics("Sorting flexion rules") ;
        qsort(rules, used, sizeof(*rules), (*rules)->compare_ptr);
        #ifdef Windows
        try
        {
        #endif
            cnt_rules = new short[cnt_chars_in_alphabet + 1];
            /*  #if defined(__GNUC__)
            					if (cnt_rules == NULL)
            						throw bad_alloc();
                #endif*/
            for (i = 0; i < cnt_chars_in_alphabet + 1; i++)
                cnt_rules[i] = 0;
            #ifndef Windows
//	catch (bad_alloc bad)
            if (cnt_rules == NULL)
            #else
        }
        catch (xalloc)
            #endif
            {
                delete[] idx_rules;
                for (i = 0; i < used; i++)
                    delete rules[i];
                delete[] rules;
                ERRMSG("Speicheranforderung fNr Zeiger 'cnt_rules' fehlgeschlagen");
            }
            for (i = 0; i < used; i++)
            {
                if (rules[i]->orth_flex.length() == 0)
                    continue;
                char ch = rules[i]->orth_flex[0];
                if (ch >= 'a' && ch <= 'z')
                    cnt_rules[ch - 'a' + 1]++;
                else if (ch == asc_sz_lig)
                    cnt_rules[0]++;
                else
                    WARNMSG("Regel mit ungNltigem Buchstaben '" << rules[i]->orth_flex << "'");
            }
            char listbuf[(cnt_chars_in_alphabet+1)*2] ;
            short dummy, j =0 ;
            for (i = 0 ; i < cnt_chars_in_alphabet+1 ; i++)
            {
                dummy = cnt_rules[i] ;
                #ifdef SUN
                dummy = bt2(dummy) ;
                #endif
                memcpy(&listbuf[j], &dummy, 2) ;
                j += 2 ;
            }
            if (!binaryfile.Create('b'))
                ERRMSG("(" << binaryfile.Filename() << "): Datei konnte nicht geöffnet werden");
            binaryfile.Write(listbuf, (cnt_chars_in_alphabet+1)*2, 1) ;
            for (i = 0; i < used; i++)
            {
                int len = rules[i]->orth_flex.length() + 1 + rules[i]->orth_base.length() + 1 + rules[i]->phon_base.length() + 1 + rules[i]->phon_flex.length() + 1 + 6 ;
                char* rulbuf = new char[len] ;
                int j = 0 ;
                memcpy(rulbuf, rules[i]->orth_flex.c_str(), rules[i]->orth_flex.length() + 1) ;
                j += rules[i]->orth_flex.length() + 1 ;
                memcpy(&rulbuf[j], rules[i]->orth_base.c_str(), rules[i]->orth_base.length() + 1) ;
                j += rules[i]->orth_base.length() + 1 ;
                memcpy(&rulbuf[j], rules[i]->phon_base.c_str(), rules[i]->phon_base.length() + 1) ;
                j += rules[i]->phon_base.length() + 1 ;
                memcpy(&rulbuf[j], rules[i]->phon_flex.c_str(), rules[i]->phon_flex.length() + 1) ;
                j += rules[i]->phon_flex.length() + 1 ;
                dummy = rules[i]->may_umlaut ;
                #ifdef SUN
                dummy = bt2(dummy) ;
                #endif
                memcpy(&rulbuf[j], &dummy, 2) ;
                j += 2 ;
                dummy = rules[i]->promote_from ;
                #ifdef SUN
                dummy = bt2(dummy) ;
                #endif
                memcpy(&rulbuf[j], &dummy, 2) ;
                j += 2 ;
                dummy = rules[i]->promote_to ;
                #ifdef SUN
                dummy = bt2(dummy) ;
                #endif
                memcpy(&rulbuf[j], &dummy, 2) ;
                j += 2 ;
                binaryfile.Write(rulbuf, j, 1) ;
                delete rules[i];
                delete (rulbuf) ;
            }
            delete[] rules;
            if (!binaryfile.Close())
                ERRMSG("(" << binaryfile.Filename() << "): Datei konnte nicht geschlossen werden");
            statistics("Flexion binary built") ;
            return true;
        }




////////////////////////////////////////////////////////////////////////////////////////

        bool TFlexion::Load (const TFile &binaryfile)
        {
            short dummy, i, j =0 ;
            // Konnte die Datei mit den bin?ren Flexionsregeln nicht geöffnet werden?
            if (!binaryfile.Open('b'))
                return false;
            // Größe der bin?ren Regeldatei feststellen
            long blocksize = binaryfile.Size();
            // Konnte die Größe nicht festgestellt werden?
            if (blocksize == -1)
            {
                // Laden der Flexionsregeln kann nicht fortgesetzt werden
                binaryfile.Close();
                return false;
            }
            // Anzahl der fNr die Regeln benötigten Bytes berechnen
            blocksize -= (cnt_chars_in_alphabet + 1) * sizeof(short);
            #ifdef _Windows
            try
            #endif
            {
                cnt_rules = new short[cnt_chars_in_alphabet + 1];
                #if defined(__GNUC__)
//					if (cnt_rules == NULL)
//						throw bad_alloc();
                #endif
            }
            #ifndef Windows
//	catch (bad_alloc bad)
            if (cnt_rules == NULL)
            #else
            catch (xalloc)
            #endif
            {
                binaryfile.Close();
                return false;
            }
            // Tabelle mit Anzahl der Regeln pro Endbuchstabe laden
            char listbuf[(cnt_chars_in_alphabet+1)*2] ;
            binaryfile.Read(listbuf, (cnt_chars_in_alphabet+1)*2, 1) ;
            for (i = 0 ; i < cnt_chars_in_alphabet+1 ; i++)
            {
                memcpy(&dummy, &listbuf[j], 2) ;
                #ifdef SUN
                dummy = bt2(dummy) ;
                #endif
                cnt_rules[i] = dummy ;
                j += 2 ;
            }
            // Anzahl der Regeln feststellen
            short cnt = 0;
            for (i = 0; i < cnt_chars_in_alphabet + 1; i++)
                cnt += cnt_rules[i];
            // Zwischenspeicher fNr die Regeln anfordern
            char* data = NULL;
            #ifdef _Windows
            try
            #endif
            {
                data = new char[blocksize + 1];
                #if defined(__GNUC__)
//					if (data == NULL)
//						throw bad_alloc();
                #endif
            }
            #ifndef Windows
//	catch (bad_alloc bad)
            if (data == NULL)
            #else
            catch (xalloc)
            #endif
            {
                binaryfile.Close();
                delete[] cnt_rules;
                cnt_rules = NULL;
                return false;
            }
            // die compilierten Regeln in den Zwischenspeicher laden
            if ((int)binaryfile.Read(data, sizeof(*data), blocksize) != blocksize)
            {
                binaryfile.Close();
                delete[] cnt_rules;
                cnt_rules = NULL;
                delete[] data;
                return false;
            }
            if (!binaryfile.Close())
                return false;
            data[blocksize] = '\0';
            // Speicher fNr die Regeln anfordern
            #ifdef _Windows
            try
            #endif
            {
                rules = new TRule[cnt];
                #if defined(__GNUC__)
//					if (rules == NULL)
//						throw bad_alloc();
                #endif
            }
            #ifndef Windows
//	catch (bad_alloc bad)
            if (rules == NULL)
            #else
            catch (xalloc)
            #endif
            {
                binaryfile.Close();
                delete[] cnt_rules;
                cnt_rules = NULL;
                delete[] data;
                return false;
            }
            // die Regeln aus dem Zwischenspeicher in die endgNltige Tabelle Nbertragen
            const char* mem = data;
            for (i = 0; i < cnt; i++)
            {
                rules[i] = TRule(mem);
//		fprintf(errfile,"%s - %s - %s - %s - %d - %d -  %d\n",rules[i].orth_flex.c_str(),rules[i].orth_base.c_str(),rules[i].phon_base.c_str(),rules[i].phon_flex.c_str(),rules[i].may_umlaut,rules[i].promote_from,rules[i].promote_to) ;
            }
            // den Zwischenspeicher wieder freigeben
            delete[] data;
            // Verweise in die Regeltabelle aufgrund der letzten Buchstaben erzeugen
            #ifdef _Windows
            try
            #endif
            {
                idx_rules = new short[cnt_chars_in_alphabet + 1];
                #if defined(__GNUC__)
//					if (idx_rules == NULL)
//						throw bad_alloc();
                #endif
            }
            #ifndef Windows
//	catch (bad_alloc bad)
            if (idx_rules == NULL)
            #else
            catch (xalloc)
            #endif
            {
                delete[] rules;
                delete[] cnt_rules;
                return false;
            }
            idx_rules[0] = 0;
            for (i = 1; i < cnt_chars_in_alphabet + 1; i++)
                idx_rules[i] = idx_rules[i - 1] + cnt_rules[i - 1];
            return (true);
        }


