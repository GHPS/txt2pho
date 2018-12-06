/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#include "lisatalk.h"
#ifdef Windows
    #include "harray.h"
#endif
#include "wrdclass.h"

class Newtable
{
    public:
        class TRecord
        {
                // das Lemma in korrekter Groß-/Kleinschreibung
                string lemma;
                // das Lemma vollst?ndig großgeschrieben
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

                const TRecord &operator= (const TRecord &rec)
                {
                    init(rec);
                    return *this;
                }

                // Zugriffsfunktionen fNr private Datenelemente
                inline const string &Lemma () const;
                inline const string &Transcription () const;
                inline const TWordClass* WordClasses () const;
                inline short WordClassesCount () const;

                // zum ÜberprNfen der Wortklassen
                bool has_word_class (TWordClass wcl) const;

            protected:
                void init (const TRecord &rec) ;
        } ;

    private:

        #ifdef Windows
        HugeArray<long>* wordstart ;
        HugeArray<unsigned char>* lexikon ;
        #else
        long* wordstart ;
        unsigned char* lexikon ;
        #endif

        long lexlen ;
        long wordcount ;
        int lexcomp(char* a, long i, int modus) ;
        long binary_Search(char* a, long start, long end) ;
        TRecord result ;

    public:

        Newtable(string datapath, string filename) ;
        ~Newtable() ;

        const long Entries() const ;
        const TRecord &operator[] (long i) ;
        long Search(string str, int locase) ;
} ;




inline const string &Newtable::TRecord::Lemma () const
{
    return lemma;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const string &Newtable::TRecord::Transcription () const
{
    return transcription;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const TWordClass* Newtable::TRecord::WordClasses () const
{
    return wordClasses;
}


////////////////////////////////////////////////////////////////////////////////////////

inline short Newtable::TRecord::WordClassesCount () const
{
    return cntWordClasses;
}





