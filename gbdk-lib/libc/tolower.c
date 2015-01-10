#include <ctype.h>

char tolower(char c) BANKED
{
  return ((c >= 'A' && c <= 'Z') ? c + 32: c);
}
