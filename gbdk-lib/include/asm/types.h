#ifndef ASM_TYPES_INCLUDE
#define ASM_TYPES_INCLUDE

#if SDCC_PORT == gbz80
#include <asm/gbz80/types.h>
#elif SDCC_PORT == z80
#include <asm/z80/types.h>
#else
#error Unrecognised port
#endif

#if GBDK_2_COMPAT
#warning This code uses the depreciated GBDK 2.0/1.0 compatible WORD/BYTE defs.

typedef INT8               BYTE;
typedef UINT8              UBYTE;
typedef INT16              WORD;
typedef UINT16             UWORD;
typedef INT32              LWORD;
typedef UINT32             ULWORD;
typedef INT32		   DWORD;
typedef UINT32		   UDWORD;

/* Useful definition for fixed point values */

typedef union _fixed {
  struct {
    UBYTE l;
    UBYTE h;
  } b;
  UWORD w;
} fixed;

#else

typedef UINT8		BYTE;
typedef UINT16		WORD;
typedef UINT32		DWORD;

#endif

#endif
