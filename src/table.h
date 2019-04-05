/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(TABLE_HEADER)
#define TABLE_HEADER


#ifdef Windows
    #include <cstring.h>
#else
    #include <string>
#endif


#include "file.h"
#include "index.h"
#include "wrdclass.h"


////////////////////////////////////////////////////////////////////////////////////////

class TTable
{
    public:
        class TRecord
        {
                // das Lemma in korrekter Groß-/Kleinschreibung
                string lemma;
                // das Lemma vollständig großgeschrieben
                string LEMMA;
                // die Transkription
                string transcription;
                // die Menge der Wortarten, denen dieses Lemma angehört
                TWordClass* wordClasses;
                // die Anzahl der Wortarten, denen dieses Lemma angehört
                short cntWordClasses;

            public:
                // Initialisierung ohne Werte
                TRecord ();
                // Copy-Konstruktor
                TRecord (const TRecord &rec) :
                    wordClasses(NULL),
                    cntWordClasses(0)
                {
                    init(rec);
                }
                // Initialisierung mit einem Speicherbereich
                TRecord (char* &mem);

                ~TRecord ();

                TRecord &operator= (const TRecord &rec)
                {
                    init(rec);
                    return *this;
                }

                // Zugriffsfunktionen für private Datenelemente
                inline const string &Lemma () const;
                inline const string &Transcription () const;
                inline const TWordClass* WordClasses () const;
                inline short WordClassesCount () const;

                // zum Überprüfen der Wortklassen
                bool has_word_class (TWordClass wcl) const;
                // Vergleichsfunktion für »qsorta und »bsearcha
                static int _USERENTRY compare (const void* cvpa, const void* cvpb);
                static int _USERENTRY compare_as_prefixes (const void* cvpa, const void* cvpb);
                static int _USERENTRY compare_ptr (const void* cvpa, const void* cvpb);
                static int _USERENTRY compare_ptr_as_prefixes (const void* cvpa, const void* cvpb);

            protected:
                void init (const TRecord &rec);

                friend class TTable;
        };

    private:
        // die Lexikondatei
        const TFile tablefile;
        mutable TRecord** records;

        const TIndex index;
        // Nummer des momentan geladenen Blocks
        mutable short loaded_block;
        // Anzahl der Einträge im momentan geladenen Block
        mutable short cnt_records_in_block;
        // Anzahl der Einträge im Lexikon
        long cnt_records;
        // lädt einen Block aus dem Lexikon nach
        void Load (short pos) const;

    public:
        TTable (const string &datapath, const string &basename);
        virtual ~TTable ();
        // findet Index zu einem Lexem
        long Search (const string &lexem, bool exactly) const;
        // Zugriffsfunktionen für private Datenelemente
        inline long Entries () const;
        const TRecord &operator[] (long i) const;
};


////////////////////////////////////////////////////////////////////////////////////////

inline const string &TTable::TRecord::Lemma () const
{
    return lemma;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const string &TTable::TRecord::Transcription () const
{
    return transcription;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const TWordClass* TTable::TRecord::WordClasses () const
{
    return wordClasses;
}


////////////////////////////////////////////////////////////////////////////////////////

inline short TTable::TRecord::WordClassesCount () const
{
    return cntWordClasses;
}


////////////////////////////////////////////////////////////////////////////////////////

inline long TTable::Entries () const
{
    return cnt_records;
}


#endif

