#include <ctype.h>

BOOLEAN isspace(char c) BANKED
{
  if(c == ' ' || c == '\t' || c == '\n')
    return 1;
  else
    return 0;
}
