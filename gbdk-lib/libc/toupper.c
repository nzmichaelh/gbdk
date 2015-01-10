#include <ctype.h>

char toupper(char c) BANKED
{
  return ((c >= 'a' && c <= 'z') ? c - 32: c);
}
