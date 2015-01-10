#include <stdarg.h>
#include <gb/drawing.h>

BYTE gprintf(char *fmt, ...)
{
  va_list ap;
  BYTE nb = 0;

  va_start(ap, fmt);
  for(; *fmt; fmt++)
    if(*fmt == '%') {
      switch(*++fmt) {
      case 'c': {
	/* char */
	  char c = va_arg(ap, char);
	  wrtchr(c);
	  break;
      }
      case 'd': {
	/* decimal int */
	  BYTE b = va_arg(ap, BYTE);
	  gprintn(b, 10, SIGNED);
	  break;
      }
      case 'u': {
	  /* unsigned int */
	  BYTE b = va_arg(ap, BYTE);
	  gprintn(b, 10, UNSIGNED);
	  break;
      }
      case 'o': {
	  /* octal int */
	  BYTE b = va_arg(ap, BYTE);
	  gprintn(b, 8, UNSIGNED);
	  break;
      }
      case 'x': {
	  /* hexadecimal int */
	  BYTE b = va_arg(ap, BYTE);
	  gprintn(b, 16, UNSIGNED);
	  break;
      }
      case 's': {
	  /* string */
	  char *s = va_arg(ap, char *);
	  gprint(s);
	  break;
      }
#if 0
      case 'l':
	/* long */
	switch(*++fmt) {
	case 'd':
	  /* decimal long */
	  gprintln(va_arg(ap, WORD), 10, SIGNED);
	  break;
	case 'u':
	  /* unsigned long */
	  gprintln(va_arg(ap, WORD), 10, UNSIGNED);
	  break;
	case 'o':
	  /* octal long */
	  gprintln(va_arg(ap, WORD), 8, UNSIGNED);
	  break;
	case 'x':
	  /* hexadecimal long */
	  gprintln(va_arg(ap, WORD), 16, UNSIGNED);
	  break;
	}
	break;
#endif
      case '%':
	/* % */
	wrtchr(*fmt);
	break;
      default:
	return -1;
      }
      nb++;
    } else
      wrtchr(*fmt);
  va_end(ap);

  return nb;
}
