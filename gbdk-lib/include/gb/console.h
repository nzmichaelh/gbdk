#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <types.h>

void
gotoxy(UINT8 x,
	   UINT8 y);

UINT8
posx(void);

UINT8
posy(void);

void
setchar(char c);

#endif /* _CONSOLE_H */
