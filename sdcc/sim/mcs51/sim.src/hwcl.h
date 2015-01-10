/*
 * Simulator of microcontrollers (hwcl.h)
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

/* Abstract hw element. It can be a timer, serial line or whatever */

#ifndef HWCL_HEADER
#define HWCL_HEADER

#include "stypes.h"
#include "pobjcl.h"
#include "uccl.h"

#include "newcmdcl.h"


class cl_hw: public cl_base
{
public:
  class cl_uc *uc;
  enum hw_cath cathegory;
  int id;
  char *id_string;

public:
  cl_hw(class cl_uc *auc, enum hw_cath cath, int aid, char *aid_string);
  ~cl_hw(void);

  virtual ulong read(class cl_mem *mem, long addr);
  virtual void write(class cl_mem *mem, long addr, ulong *val);

  virtual int tick(int cycles);
  virtual void print_info(class cl_console *con);
};


#endif

/* End of hwcl.h */