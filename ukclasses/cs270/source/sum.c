#include <stdio.h>
#include <stdlib.h>

void sumstore(long x, long y,
              long *dest)
{
  long t = x + y;
  *dest = t;
}

int main(int argc, char *argv[])
{
  long x = atol(argv[1]);
  long y = atol(argv[2]);

  long result;
  sumstore(x, y, &result);
  printf("%ld\n", result);
  return 0;
}