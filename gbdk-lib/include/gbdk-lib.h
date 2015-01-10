#ifndef GBDK_LIB_INCLUDE
#define GBDK_LIB_INCLUDE

#define USE_C_MEMCPY		1
#define USE_C_STRCPY		1
#define USE_C_STRCMP		1

#if SDCC_PORT==gbz80
#include <asm/gbz80/provides.h>
#elif SDCC_PORT==z80
#include <asm/z80/provides.h>
#else
#error Unrecognised port.
#endif

#endif
