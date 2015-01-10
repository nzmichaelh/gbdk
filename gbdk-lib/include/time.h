/** @file time.h
    Sort of ANSI compliant time functions.
*/
#ifndef TIME_INCLUDE
#define TIME_INCLUDE

#include <types.h>

/** For now... */
#define CLOCKS_PER_SEC		50

/** The clock() function returns an approximation of processor time
    used by the program.  The value returned is the CPU time used so far
    as a clock_t; to get the number of seconds used, divide by
    CLOCKS_PER_SEC.
*/
clock_t clock(void);

#endif
