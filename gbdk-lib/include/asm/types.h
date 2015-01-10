#ifndef ASM_TYPES_INCLUDE
#define ASM_TYPES_INCLUDE

#if SDCC_PORT == gbz80
#include <asm/gbz80/types.h>
#elif SDCC_PORT == z80
#include <asm/z80/types.h>
#else
#error Unrecognised port
#endif

typedef INT8		BOOLEAN;

#if BYTE_IS_UNSIGNED

typedef UINT8		BYTE;
typedef UINT16		WORD;
typedef UINT32		DWORD;

#else

typedef INT8         	BYTE;
typedef UINT8        	UBYTE;
typedef INT16      	WORD;
typedef UINT16       	UWORD;
typedef INT32       	LWORD;
typedef UINT32      	ULWORD;
typedef INT32	   	DWORD;
typedef UINT32	   	UDWORD;

/* Useful definition for fixed point values */

typedef union _fixed {
  struct {
    UBYTE l;
    UBYTE h;
  } b;
  UWORD w;
} fixed;

#endif

#endif
