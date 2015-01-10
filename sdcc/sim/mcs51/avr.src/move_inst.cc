/*
 * Simulator of microcontrollers (move_inst.cc)
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

#include "avrcl.h"


int
cl_avr::lpm(uint code)
{
  return(resGO);
}


int
cl_avr::elpm(uint code)
{
  return(resGO);
}


int
cl_avr::spm(uint code)
{
  return(resGO);
}


int
cl_avr::espm(uint code)
{
  return(resGO);
}


/*
 * Load Immediate
 * LDI Rd,K 16<=d<=31 0<=K<=255
 * 1110 KKKK dddd KKKK
 *____________________________________________________________________________
 */

int
cl_avr::ldi_Rd_K(uint code)
{
  uint d, K;

  d= (code&0xf0)>>4;
  K= ((code&0xf00)>>4)|(code&0xf);
  write_mem(MEM_IRAM, d, K);
  return(resGO);
}


int
cl_avr::movw_Rd_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::ldd_Rd_Z_q(uint code)
{
  return(resGO);
}


int
cl_avr::ldd_Rd_Y_q(uint code)
{
  return(resGO);
}


int
cl_avr::st_Z_q_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::std_Y_q_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::lds_Rd_k(uint code)
{
  return(resGO);
}


int
cl_avr::ld_Rd_Z$(uint code)
{
  return(resGO);
}


int
cl_avr::ld_Rd_$Z(uint code)
{
  return(resGO);
}


int
cl_avr::lpm_Rd_Z(uint code)
{
  return(resGO);
}


int
cl_avr::lpm_Rd_Z$(uint code)
{
  return(resGO);
}


int
cl_avr::elpm_Rd_Z(uint code)
{
  return(resGO);
}


int
cl_avr::elpm_Rd_Z$(uint code)
{
  return(resGO);
}


int
cl_avr::ld_Rd_Y$(uint code)
{
  return(resGO);
}


int
cl_avr::ld_Rd_$Y(uint code)
{
  return(resGO);
}


int
cl_avr::ld_Rd_X(uint code)
{
  return(resGO);
}


int
cl_avr::ld_Rd_X$(uint code)
{
  return(resGO);
}


int
cl_avr::ld_Rd_$X(uint code)
{
  return(resGO);
}


int
cl_avr::pop_Rd(uint code)
{
  return(resGO);
}


int
cl_avr::sts_k_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::st_Z$_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::st_$Z_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::st_Y$_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::st$Y_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::st_X_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::st_X$_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::st_$X_Rr(uint code)
{
  return(resGO);
}


int
cl_avr::push_Rr(uint code)
{
  return(resGO);
}


/*
 * Swap Nibbles
 * SWAP Rd 0<=d<=31
 * 1001 010d dddd 0010
 *____________________________________________________________________________
 */

int
cl_avr::swap_Rd(uint code)
{
  uint d, data, temp;

  d= (code&0x1f0)>>4;
  data= read_mem(MEM_IRAM, d);
  temp= (data>>4)&0xf;
  write_mem(MEM_IRAM, d, (data<<4)|temp);
  return(resGO);
}


/*
 * Load an I/O Port to Register
 * IN Rd,P 0<=d<=31 0<=P<=63
 * 1011 0PPd dddd PPPP
 *____________________________________________________________________________
 */

int
cl_avr::in_Rd_A(uint code)
{
  uint P, d;
  
  P= ((code&0x600)>>5)|(code&0xf);
  d= (code&0x1f0)>>4;
  write_mem(MEM_IRAM, d, read_mem(MEM_IRAM, P+0x20));
  return(resGO);
}


/*
 * Store Register to I/O Port
 * OUT P,Rr 0<=r<=31 0<=P<=63
 * 1011 1PPr rrrr PPPP
 *____________________________________________________________________________
 */

int
cl_avr::out_A_Rr(uint code)
{
  uint P, r;
  
  P= ((code&0x600)>>5)|(code&0xf);
  r= (code&0x1f0)>>4;
  write_mem(MEM_IRAM, P+0x20, read_mem(MEM_IRAM, r));
  return(resGO);
}


/*
 * Copy Register
 * MOV Rd,Rr 0<=d<=31 0<=r<=31
 * 0010 11rd dddd rrrr
 *____________________________________________________________________________
 */

int
cl_avr::mov_Rd_Rr(uint code)
{
  uint d, r;

  d= (code&0x1f0)>>4;
  r= ((code&0x200)>>5)|(code&0xf);
  write_mem(MEM_IRAM, d, read_mem(MEM_IRAM, r));
  return(resGO);
}


/* End of move_inst.cc */
