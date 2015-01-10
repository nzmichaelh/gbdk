#include <ctype.h>

BOOLEAN isupper(char c) BANKED
{
  if(c >= 'A' && c <= 'Z')
    return 1;
  else
    return 0;
}
