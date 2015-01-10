#include <stdlib.h>
#include <types.h>

int abs(int num) BANKED
{
  if(num < 0)
    return -num;
  else
    return num;
}
