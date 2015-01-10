/*
 * Simulator of microcontrollers (bit_inst.cc)
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

// local
#include "avrcl.h"
#include "regsavr.h"


/*
 * Set Carry Flag
 * SEC
 * 1001 0100 0000 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::sec(uint code)
{
  write_mem(MEM_IRAM, SREG, BIT_C | read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Set Negative Flag
 * SEN
 * 1001 0100 0010 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::sen(uint code)
{
  write_mem(MEM_IRAM, SREG, BIT_N | read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Set Zero Flag
 * SEZ
 * 1001 0100 0001 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::sez(uint code)
{
  write_mem(MEM_IRAM, SREG, BIT_Z | read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Set Global Interrupt Flag
 * SEI
 * 1001 0100 0111 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::sei(uint code)
{
  write_mem(MEM_IRAM, SREG, BIT_I | read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Set Signed Flag
 * SES
 * 1001 0100 0100 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::ses(uint code)
{
  write_mem(MEM_IRAM, SREG, BIT_S | read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Set Overflow Flag
 * SEV
 * 1001 0100 0011 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::sev(uint code)
{
  write_mem(MEM_IRAM, SREG, BIT_V | read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Set T Flag
 * SET
 * 1001 0100 0110 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::set(uint code)
{
  write_mem(MEM_IRAM, SREG, BIT_T | read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Set Half Carry Flag
 * SEH
 * 1001 0100 0101 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::seh(uint code)
{
  write_mem(MEM_IRAM, SREG, BIT_H | read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Clear Carry Flag
 * CLC
 * 1001 0100 1000 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::clc(uint code)
{
  write_mem(MEM_IRAM, SREG, ~BIT_C & read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Clear Negative Flag
 * CLN
 * 1001 0100 1010 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::cln(uint code)
{
  write_mem(MEM_IRAM, SREG, ~BIT_N & read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Clear Zero Flag
 * CLZ
 * 1001 0100 1001 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::clz(uint code)
{
  write_mem(MEM_IRAM, SREG, ~BIT_Z & read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Global Interrupt Flag
 * CLI
 * 1001 0100 1111 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::cli(uint code)
{
  write_mem(MEM_IRAM, SREG, ~BIT_I & read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Clear Signed Flag
 * CLS
 * 1001 0100 1100 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::cls(uint code)
{
  write_mem(MEM_IRAM, SREG, ~BIT_S & read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Clear Overflow Flag
 * CLV
 * 1001 0100 1011 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::clv(uint code)
{
  write_mem(MEM_IRAM, SREG, ~BIT_V & read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Clear T Flag
 * CLT
 * 1001 0100 1110 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::clt(uint code)
{
  write_mem(MEM_IRAM, SREG, ~BIT_T & read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Clear Half Carry Flag
 * CLH
 * 1001 0100 1101 1000
 *----------------------------------------------------------------------------
 */

int
cl_avr::clh(uint code)
{
  write_mem(MEM_IRAM, SREG, ~BIT_H & read_mem(MEM_IRAM, SREG));
  return(resGO);
}


/*
 * Clear Bit in I/O Register
 * CBI P,b 0<=P<=31 0<=b<=7
 * 1001 1000 pppp pbbb
 *____________________________________________________________________________
 */

int
cl_avr::cbi_A_b(uint code)
{
  uint addr, mask;
  
  addr= ((code&0xf8)>>3)+0x20;
  mask= 1 << (code&7);
  write_mem(MEM_IRAM, addr, ~mask & read_mem(MEM_IRAM, addr));
  tick(1);
  return(resGO);
}


/*
 * Set Bit in I/O Register
 * SBI P,b 0<=P<=31 0<=b<=7
 * 1001 1010 pppp pbbb
 *____________________________________________________________________________
 */

int
cl_avr::sbi_A_b(uint code)
{
  uint addr, mask;
  
  addr= ((code&0xf8)>>3)+0x20;
  mask= 1 << (code&7);
  write_mem(MEM_IRAM, addr, mask | read_mem(MEM_IRAM, addr));
  tick(1);
  return(resGO);
}


/*
 * Skip if Bit in I/O Register is Clear
 * SBIC P,b 0<=P<=31 0<=b<=7
 * 1001 1001 pppp pbbb
 *____________________________________________________________________________
 */

int
cl_avr::sbic_A_b(uint code)
{
  uint addr, mask;
  
  addr= ((code&0xf8)>>3)+0x20;
  mask= 1 << (code&7);
  if (0 == (mask & read_mem(MEM_IRAM, addr)))
    {
      code= fetch();
      int size= inst_length(code);
      while (size > 1)
	{
	  fetch();
	  size--;
	}
      tick(1);
    }
  return(resGO);
}


/*
 * Skip if Bit in I/O Register is Set
 * SBIS P,b 0<=P<=31 0<=b<=7
 * 1001 1011 pppp pbbb
 *____________________________________________________________________________
 */

int
cl_avr::sbis_A_b(uint code)
{
  uint addr, mask;
  
  addr= ((code&0xf8)>>3)+0x20;
  mask= 1 << (code&7);
  if (mask & read_mem(MEM_IRAM, addr))
    {
      code= fetch();
      int size= inst_length(code);
      while (size > 1)
	{
	  fetch();
	  size--;
	}
      tick(1);
    }
  return(resGO);
}


/* End of bit_inst.cc */
