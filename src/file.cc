
#include "file.h"

#ifdef _Windows

#if !defined(__IO_H)
#include <io.h>
#endif
#if !defined(__STDARG_H)
#include <stdarg.h>
#endif
#if !defined(__STDIO_H)
#include <stdio.h>
#endif

#else

#include <climits>
#include <cstdarg>
#include <cstdio>
#include <unistd.h>

#endif

////////////////////////////////////////////////////////////////////////////////////////

TFile::TFile () :
	flags(0),
	stream(NULL),
	isOpen(false)
{
#ifdef _Windows
   drive = path = name = extension = "";
#endif

}


////////////////////////////////////////////////////////////////////////////////////////

TFile::TFile (const string &fn) :
	flags(0),
	stream(NULL),
	isOpen(false)
{
	int pos;


#ifdef _Windows
#ifndef __MSDOS__
#define __MSDOS__
#endif
#endif

#ifndef _Windows
#if defined(__MSDOS__)
	int last_colon = ((pos = fn.rfind(':'))     != string::npos) ? pos : -1;
#endif
	int last_slash = ((pos = (int)fn.rfind(DIR_SEP)) != (int)string::npos) ? pos : -1;
	int last_dot   = ((pos = (int)fn.rfind('.'))     != (int)string::npos) ? pos : -1;

#if defined(__MSDOS__)
	if (last_colon != -1)
		drive = string(fn, 0, last_colon + 1);

	if (last_slash != -1)
		path = string(fn, last_colon + 1, last_slash - last_colon);

	int last_sep = max(last_colon, last_slash);

	if (last_dot != -1 && last_dot > last_sep)
	{
		name = string(fn, last_sep + 1, last_dot - last_sep - 1);
		extension = string(fn, last_dot);
	}
	else
		name = string(fn, last_sep + 1);
#else
	if (last_slash != -1)
		path = string(fn, 0, last_slash + 1);

	if (last_dot != -1 && last_dot > last_slash)
	{
		name = string(fn, last_slash + 1, last_dot - last_slash - 1);
		extension = string(fn, last_dot);
	}
	else
		name = string(fn, last_slash + 1);
#endif
#else
	char __name[MAXPATH];
	char __drive[MAXDRIVE];
	char __dir[MAXDIR];
	char __file[MAXFILE];
	char __ext[MAXEXT];

	_fullpath(__name, fn.c_str(), sizeof(__name));
	strlwr(__name);
	if (fn[fn.length() - 1] == '\\')
		strcat(__name, "\\");

	flags = fnsplit(__name, __drive, __dir, __file, __ext);
	drive.append((const char*) __drive) ;
	path.append((const char*)__dir) ;
	name.append((const char*)__file) ;
	extension.append((const char*) __ext) ;

	stream = NULL;
	isOpen = false;

#endif
	setFilename();
}


////////////////////////////////////////////////////////////////////////////////////////

TFile::~TFile ()
{
	if (isOpen)
		Close();
}


////////////////////////////////////////////////////////////////////////////////////////

void TFile::setFilename ()
{
	filename = drive + path + name + extension;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::Open (char mode) 
#ifndef _Windows
	const
#endif

{
//	fprintf(stderr,"ENTERING FILE\n") ;
//	fflush(stderr) ;
	if (mode != 'b' && mode != 't')
		return false;
//	fprintf(stderr,"NOW IN FILE\n") ;
//	fflush(stderr) ;
	char *modestr = (char*)((mode == 'b') ? "rb" : "rt");
//	if (!isOpen)
//	{
		
		stream = fopen(Filename().c_str(), modestr);
		isOpen = stream != NULL;
//		fprintf(stderr,"%s %s %d\n",Filename().c_str(),modestr,isOpen) ;
//	}
//	fprintf(stderr,"Resultat %d\n",isOpen) ;
//	fflush(stderr) ;
	return isOpen;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::OpenAsReadWrite (char mode)
{
	if (mode != 'b' && mode != 't')
		return false;

	if (!isOpen)
	{
		TFile *self = const_cast<TFile *>(this);
		char *modestr = (char*)((mode == 'b') ? "r+b" : "r+t");

		self->stream = fopen(Filename().c_str(), modestr);
		self->isOpen = stream != NULL;
	}
	return isOpen;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::Create (char mode)
{
	if (mode != 'b' && mode != 't')
		return false;

	if (!isOpen)
	{
		char *modestr = (char*)((mode == 'b') ? "wb" : "wt");

		stream = fopen(Filename().c_str(), modestr);
		isOpen = stream != NULL;
	}
	return isOpen;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::CreateAsReadWrite (char mode)
{
	if (mode != 'b' && mode != 't')
		return false;

	if (!isOpen)
	{
		char *modestr =(char*)((mode == 'b') ? "w+b" : "w+t");

		stream = fopen(Filename().c_str(), modestr);
		isOpen = stream != NULL;
	}
	return isOpen;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::Append (char mode)
{
	if (mode != 'b' && mode != 't')
		return false;

	if (!isOpen)
	{
		char *modestr = (char*)((mode == 'b') ? "ab" : "at");

		stream = fopen(Filename().c_str(), modestr);
		isOpen = stream != NULL;
	}
	return isOpen;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::AppendAsReadWrite (char mode)
{
	if (mode != 'b' && mode != 't')
		return false;

	if (!isOpen)
	{
		char *modestr = (char*)((mode == 'b') ? "a+b" : "a+t");

		stream = fopen(Filename().c_str(), modestr);
		isOpen = stream != NULL;
	}
	return isOpen;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::Close () const
{
	TFile *self = const_cast<TFile *>(this);
	bool result = true;

	if (isOpen)
	{
		result = fclose(static_cast<FILE *>(stream)) == 0;
		self->stream = NULL;
		self->isOpen = false;
	}
	return result;
}


////////////////////////////////////////////////////////////////////////////////////////

long TFile::Size () const
{
	struct stat st;
	int res = Stat(st);

	if (res != 0)
		return -1;
	else
		return st.st_size;
}


////////////////////////////////////////////////////////////////////////////////////////

size_t TFile::Read (void *ptr, size_t size, size_t n) const
{
	return (isOpen) ? fread(ptr, size, n, static_cast<FILE *>(stream)) : 0;
}


////////////////////////////////////////////////////////////////////////////////////////

size_t TFile::Write (const void *ptr, size_t size, size_t n)
{
	return (isOpen) ? fwrite(ptr, size, n, static_cast<FILE *>(stream)) : 0;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::Rewind () const
{
	if (!isOpen)
		return false;
	rewind(static_cast<FILE *>(stream));
	return true;
}


////////////////////////////////////////////////////////////////////////////////////////

long TFile::Tell () const
{
	return (isOpen) ? ftell(static_cast<FILE *>(stream)) : -1L;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::SeekFromStart (long offset) const
{
	return Seek(offset, SEEK_SET);
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::SeekRelative (long offset) const
{
	return Seek(offset, SEEK_CUR);
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::SeekFromEnd (long offset) const
{
	return Seek(offset, SEEK_END);
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::EoF () const
{
	if (!isOpen)
		return true;
	return feof(static_cast<FILE *>(stream)) != 0;
}


////////////////////////////////////////////////////////////////////////////////////////

int TFile::ScanF (long int *l) const
{
	if (!isOpen)
		return 0;

	return fscanf(static_cast<FILE *>(stream), "%ld", l);
}


////////////////////////////////////////////////////////////////////////////////////////

int TFile::ScanF (char *s) const
{
	if (!isOpen)
		return 0;

	return fscanf(static_cast<FILE *>(stream), "%s", s);
}


////////////////////////////////////////////////////////////////////////////////////////

int TFile::PrintF (const char *format, ...)
{
	if (!isOpen)
		return 0;

	va_list  argptr;
	int cnt;

	va_start(argptr, format);
	cnt = vfprintf(static_cast<FILE *>(stream), format, argptr);
	va_end(argptr);

	return cnt;
}


////////////////////////////////////////////////////////////////////////////////////////

char *TFile::GetS (char *s, int n) const
{
	return (isOpen) ? fgets(s, n, static_cast<FILE *>(stream)) : 0;
}


////////////////////////////////////////////////////////////////////////////////////////

int TFile::PutS (char *s)
{
	return (isOpen) ? fputs(s, static_cast<FILE *>(stream)) : EOF;
}


////////////////////////////////////////////////////////////////////////////////////////

int TFile::Stat (struct stat &st) const
{
	return stat(Filename().c_str(), &st);
}


////////////////////////////////////////////////////////////////////////////////////////

long TFile::ModifyTime () const
{
	struct stat st;
	int res = Stat(st);

	if (res != 0)
		return -1;
	else
		return st.st_mtime;
}


////////////////////////////////////////////////////////////////////////////////////////

long TFile::AccessTime () const
{
	struct stat st;
	int res = Stat(st);

	if (res != 0)
		return -1;
	else
		return st.st_atime;
}


////////////////////////////////////////////////////////////////////////////////////////

long TFile::CreateTime () const
{
	struct stat st;
	int res = Stat(st);

	if (res != 0)
		return -1;
	else
		return st.st_ctime;
}


////////////////////////////////////////////////////////////////////////////////////////

bool TFile::Exists () const
{
	bool result = isOpen;

	if (!result)
		result = access(Filename().c_str(), 0) == 0;
	return result;
}


////////////////////////////////////////////////////////////////////////////////////////

void TFile::init (const TFile &file)
{
	if (this == &file)
		return;

	flags = file.flags;
	drive = file.drive;
	path = file.path;
	name = file.name;
	extension = file.extension;

	stream = file.stream;
	isOpen = file.isOpen;

	setFilename();
}

////////////////////////////////////////////////////////////////////////////////////////

bool TFile::Seek (long offset, int whence) const
{
	if (!isOpen)
		return false;
	return fseek(static_cast<FILE *>(stream), offset, whence) == 0;
}

