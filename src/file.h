/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(FILE_HEADER)
#define FILE_HEADER

using namespace std ;

#ifndef _Windows
    #include <climits>
    #include <string>
#else
    #include <cstring.h>
    #include <dir.h>
    #include <limits.h>
    #include <values.h>
    #include <sys/stat.h>
    #include <classlib/defs.h>
#endif

#include <sys/stat.h>


#if defined(__MSDOS__)
    #define DIR_SEP '\\'
#else
    #define DIR_SEP '/'
#endif


////////////////////////////////////////////////////////////////////////////////////////

class TFile
{
    private:
        string filename;
        string drive;
        string path;
        string name;
        string extension;

        int flags;

        mutable void* stream;
        mutable bool isOpen;

        void setFilename ();

    public:
        TFile ();
        TFile (const TFile &file)
        {
            init(file);
        }
        TFile (const string &filename);

        virtual ~TFile ();

        TFile &operator= (const TFile &file)
        {
            init(file);
            return *this;
        }

        const string &Filename () const
        {
            return filename;
        }
        const string &Drive () const
        {
            return drive;
        }
        const string &Path () const
        {
            return path;
        }
        const string &Name () const
        {
            return name;
        }
        const string &Extension () const
        {
            return extension;
        }

        bool Open (char mode)
        #ifndef _Windows
        const
        #endif
        ;
        bool OpenAsReadWrite (char mode);
        bool Create (char mode);
        bool CreateAsReadWrite (char mode);
        bool Append (char mode);
        bool AppendAsReadWrite (char mode);

        bool Close () const;

        long Size () const;
        size_t Read (void* ptr, size_t size, size_t n) const;
        size_t Write (const void* ptr, size_t size, size_t n);
        bool Rewind () const;
        long Tell () const;
        bool SeekFromStart (long offset) const;
        bool SeekRelative (long offset) const;
        bool SeekFromEnd (long offset) const;
        bool EoF () const;

        int ScanF (long int* l) const;
        int ScanF (char* s) const;
        int PrintF (const char* format, ...);
        char* GetS (char* s, int n) const;
        int PutS (char* s);

        long ModifyTime () const;
        long AccessTime () const;
        long CreateTime () const;

        bool IsOpen () const
        {
            return isOpen;
        }
        bool IsClosed () const
        {
            return !isOpen;
        }
        bool IsAbsolute () const
        {
            return path[0] == DIR_SEP;
        }
        bool IsRelative () const
        {
            return path[0] != DIR_SEP;
        }
        bool Exists () const;

        inline bool IsDrive () const;
        inline bool IsPath () const;
        inline bool IsFile () const;

    protected:
        void init (const TFile &file);
        bool Seek (long offset, int whence) const;
        int Stat (struct stat &st) const;
};


////////////////////////////////////////////////////////////////////////////////////////

inline bool TFile::IsDrive () const
{
    #ifndef _Windows
    return !drive.empty() && path.empty() && name.empty() && extension.empty();
    #else
    return (!drive.is_null() && path.is_null() && name.is_null() && extension.is_null()) ? true : false;
    #endif
}


////////////////////////////////////////////////////////////////////////////////////////

inline bool TFile::IsPath () const
{
    #ifndef _Windows
    return !path.empty() && name.empty() && extension.empty();
    #else
    return (!path.is_null() && name.is_null() && extension.is_null()) ? true : false;
    #endif
}


////////////////////////////////////////////////////////////////////////////////////////

inline bool TFile::IsFile () const
{
    #ifndef _Windows
    return !name.empty();
    #else
    return (!name.is_null()) ? true : false;
    #endif
}


#endif

