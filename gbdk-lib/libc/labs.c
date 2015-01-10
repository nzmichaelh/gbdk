#include <stdlib.h>
#include <types.h>

long labs(long num) BANKED
{
  if(num < 0)
    return -num;
  else
    return num;
}
