#include <ctype.h>

BOOLEAN islower(char c) BANKED
{
  if(c >= 'a' && c <= 'z')
    return 1;
  else
    return 0;
}
