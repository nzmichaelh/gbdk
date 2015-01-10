#include <ctype.h>

BOOLEAN isalpha(char c) BANKED
{
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return 1;
  else
    return 0;
}
