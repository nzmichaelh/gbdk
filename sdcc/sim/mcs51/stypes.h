/*
 * Simulator of microcontrollers (stypes.h)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/

#ifndef STYPES_HEADER
#define STYPES_HEADER

#include "ddconfig.h"


typedef unsigned char uchar;
typedef unsigned int  uint;
typedef unsigned long ulong;
typedef unsigned long t_addr;
typedef unsigned long t_mem;

struct id_element
{
  int id;
  char *id_string;
};

// table of dissassembled instructions
struct dis_entry
{
  uint  code, mask;
  char  branch;
  uchar length;
  char  *mnemonic;
};

// table entry of SFR and BIT names
struct name_entry
{
  int  cpu_type;
  uint addr;
  char *name;
};


struct cpu_entry
{
  char *type_str;
  int  type;
  int  technology;
};

#define CPU_51		0x01
#define CPU_31		0x02
#define CPU_52		0x04
#define CPU_32		0x08
#define CPU_51R		0x10
#define CPU_89C51R	0x20
#define CPU_251		0x40

#define CPU_ALL_51	(CPU_51|CPU_31)
#define CPU_ALL_52	(CPU_52|CPU_32|CPU_51R|CPU_89C51R|CPU_251)

#define CPU_AVR		0x01

#define CPU_ALL_AVR	(CPU_AVR)

#define CPU_CMOS	0x01
#define CPU_HMOS	0x02

/* Classes of memories */
enum mem_class
{
  MEM_ROM= 0,
  MEM_XRAM,
  MEM_IRAM,
  MEM_SFR,
  MEM_TYPES
};

// States of simulator
#define SIM_NONE	0
#define SIM_GO		0x01	// Processor is running
#define SIM_QUIT	0x02	// Program must exit

// Flags of consoles
#define CONS_NONE	0
#define CONS_DEBUG	0x01	// Print debug messages on this console
#define CONS_FROZEN	0x02	// Console is frozen (g command issued)

/* State of the CPU */
#define stGO		0 /* Normal state */
#define stIDLE		1 /* Idle mode is active */
#define stPD		2 /* Power Down mode is active */

/* Result of instruction simulation */
#define resGO		0   /* OK, go on */
#define resWDTRESET	1   /* Reseted by WDT */
#define resINTERRUPT	2   /* Interrupt accepted */
#define resSTOP		100 /* Stop if result greather then this */
#define resHALT		101 /* Serious error, halt CPU */
#define resINV_ADDR	102 /* Invalid indirect address */
#define resSTACK_OV	103 /* Stack overflow */
#define resBREAKPOINT	104 /* Breakpoint */
#define resUSER		105 /* Stopped by user */
#define resINV_INST	106 /* Invalid instruction */


#define BIT_MASK(bitaddr) (1 << (bitaddr & 0x07))
#define SET_BIT(newbit, reg, bitmask) \
if (newbit) \
  (mem(MEM_SFR))->set_bit1((reg), (bitmask)); \
else \
  (mem(MEM_SFR))->set_bit0((reg), (bitmask));
#define GET_C (get_mem(MEM_SFR, PSW) & bmCY)
#define SET_C(newC) SET_BIT((newC), PSW, bmCY)

#define IRAM_SIZE 256	  /* Size of Internal RAM */
#define SFR_SIZE  256     /* Size of SFR area */
#define SFR_START 128     /* Start address of SFR area */
#define ERAM_SIZE 256     /* Size of ERAM in 51R */
#define XRAM_SIZE 0x10000 /* Size of External RAM */
//#define IROM_SIZE 0x1000  /* Size of Internal ROM */
#define EROM_SIZE 0x10000 /* Size of External ROM */


/* Type of breakpoints */
enum brk_perm
{
  brkFIX,	/* f */
  brkDYNAMIC	/* d */
};

enum brk_type
{
  brkFETCH,	/* f */
  brkEVENT	/* e */
};

enum brk_event
{
  brkNONE,
  brkWXRAM,	/* wx */
  brkRXRAM,	/* rx */
  brkRCODE,	/* rc */
  brkWIRAM,	/* wi */
  brkRIRAM,	/* ri */
  brkWSFR,	/* ws */
  brkRSFR	/* rs */
};

struct event_rec
{
  int wx; /* write to XRAM at this address, else -1 */
  int rx; /* read from XRAM at this address, else -1 */
  int wi; /* write to IRAM at this address, else -1 */
  int ri; /* read from IRAM at this address, else -1 */
  int ws; /* write to SFR at this address, else -1 */
  int rs; /* read from SFR at this address, else -1 */
  int rc; /* read from ROM at this address, else -1 */
};

/* Interrupt levels */
#define IT_NO		-1 /* not in interroupt service */
#define IT_LOW		1 /* low level interrupt service */
#define IT_HIGH		2 /* service of high priority interrupt */

/* cathegories of hw elements (peripherials) */
enum hw_cath {
  HW_TIMER,
  HW_UART,
  HW_PORT,
  HW_PCA,
  HW_INTERRUPT
};


#endif

/* End of stypes.h */
