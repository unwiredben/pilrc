/*
 * @(#)util.h
 *
 * Copyright 1997-1999, Wes Cherry   (mailto:wesc@technosis.com)
 *           2000-2004, Aaron Ardiri (mailto:aaron@ardiri.com)
 * All rights reserved.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation;  either version 2, or (at your option)
 * any version.
 *
 * This program is distributed in the hope that it will be useful,  but
 * WITHOUT  ANY  WARRANTY;   without  even   the  implied  warranty  of 
 * MERCHANTABILITY  or FITNESS FOR A  PARTICULAR  PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You  should have  received a  copy of the GNU General Public License
 * along with this program;  if not,  please write to the Free Software 
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * Revisions:
 * ==========
 *
 * pre 18-Jun-2000 <numerous developers>
 *                 creation
 *     18-Jun-2000 Aaron Ardiri
 *                 GNU GPL documentation additions
 */

#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include <stdarg.h>
#include "std.h"

/*
 * RMa add : Debug mode define 
 */
#ifdef _DEBUG
#define		HEXOUT		1
#endif

#ifdef __GNUC__
#define PRINTF_FORMATTING  __attribute__ ((format(printf, 1, 2)))
#else
#define PRINTF_FORMATTING
#endif

/* Error() and ErrorLine() write a message to stderr and halt translation;
   WarningLine() writes to stderr and returns.  ErrorLine() and WarningLine()
   add an indication of the current source file and line number to the message
   given via the printf format etc arguments.  */

VOID Error(const char *szFormat, ...)  PRINTF_FORMATTING;
VOID Error2(const char *sz1,
            const char *sz2);
VOID Error3(const char *sz1,
            const char *sz2,
            const char *sz3);
VOID ErrorLine(const char *szFormat, ...)    PRINTF_FORMATTING;
VOID WarningLine(const char *szFormat, ...)  PRINTF_FORMATTING;
VOID ErrorLine2(const char *sz,
                const char *sz2);

/* The functions above are actually wrappers around this general purpose
   diagnostic function.  Generally there's no need to call this directly,
   but in any case: fError distinguishes between error/warning, and if
   filename is NULL then it's a non-localised dianostic, as for Error().  */

VOID Diagnostic(BOOL fError, const char *filename, int lineno,
                const char *szFormat, va_list *args);

/*lint -function(exit,Error) */
/*lint -function(exit,Error2) */
/*lint -function(exit,Error3) */
/*lint -function(exit,ErrorLine) */
/*lint -function(exit,ErrorLine2) */
/*lint -function(exit,Diagnostic) */

BOOL FSzEqI(const char *sz1,
            const char *sz2);
int WMin(int w1,
         int w2);
int WMax(int w1,
         int w2);

VOID EmitB(BYTE b);
VOID EmitW(unsigned short w);
VOID EmitL(unsigned long l);

VOID intstrncpy(p_int * dst,
                const char *src,
                int n);

/*
 * void SwapBytes(void *pv, int cb); 
 */

/*
 * void SwapLong(void *pl); 
 */

/*
 * void SwapStruct(void *pv, char *szPic); 
 */
VOID OpenOutput(char *szBase,
                int id);
VOID CloseOutput(void);
FILE *getOpenedOutputFile(void);

VOID SetOutFileDir(const char *sz);

VOID OpenResDBFile(const char *szFile);
VOID CloseResDBFile(void);

VOID OpenResFile(const char *szFile);
VOID CloseResFile(void);
VOID DumpBytes(void *pv,
               int cb);
VOID PadBoundary(void);
VOID PadWordBoundary(void);
int IbOut(void);
void AddAccessPath(const char *path);
void FreeAccessPathsList(void);
const char *FindAndOpenFile(const char *szIn,
                      const char *mode,
                      FILE ** returnFile);

void SetDependsTarget(const char *szIn);
void InitDependsList(void);
void AddEntryToDependsList(const char *filename);
void OutputDependsList(FILE *dependsFile);
void FreeDependsList(void);

extern char rgbZero[];
extern FILE *vfhIn;

#ifdef CW_PLUGIN
// XXX ncr
#undef feof
#define feof(f)    MyFeof(f)
#endif

#endif
