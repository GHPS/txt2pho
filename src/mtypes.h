/*
 *  <mtypes.h - abstract type definition to port the library to systems
 *   with sized types other than UNIX.>
 *  Copyright (C) 1995 <Karlheinz St"ober>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  This file is part of libdsp.a
 *
 *  email: kst@ikp.uni-bonn.de
 */

#ifndef __MTYPESH__
#define __MTYPESH__

typedef short                        t_Short;  // 2 Byte integer (Data  type)
typedef int                          t_Int;    // 4 Byte integer (Index type)
typedef long                         t_Long;   // 4 Byte integer
typedef float                        t_Float;  // 4 Byte real
typedef double                       t_Double; // X Byte real
typedef float                        t_Vector; // 4 Byte real
typedef int                          t_Index;  // 4 Byte int

#ifdef HAS_BOOL
 typedef enum {false, true}           bool;
#endif

typedef enum {mforward, minverse}    MDirTyp;
typedef enum {all, minima, maxima}   ExtremaTyp;

#endif
