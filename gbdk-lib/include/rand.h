#ifndef RAND_INCLUDE
#define RAND_INCLUDE

#include <types.h>


/*
 * Random generator using the linear congruential method
 *
 * Author: Luc Van den Borre
 */

void
initrand(UWORD seed);

BYTE
rand(void);

WORD
randw(void);

/*
 * Random generator using the linear lagged additive method
 *
 * Author: Luc Van den Borre
 *
 * Note that 'initarand()' calls 'initrand()' with the same seed value, and
 * uses 'rand()' to initialize the random generator.
 */

void
initarand(WORD seed);

BYTE
arand(void);

#endif
