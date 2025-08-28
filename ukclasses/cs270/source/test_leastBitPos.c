#include <stdio.h>

/* return a mask with a one in the position of the least significant 1  bit
 * in the argument, if any. */
int leastBitPos(int x) {
  int xtilde, xtplus1, retval; /* variables must be declared first for P0 */
  xtilde = ~x;
  xtplus1 = xtilde+1;
  retval = x & xtplus1;
  return retval;
}

int main() {
  int inputval = 0x98765430; /* 1001 1000 0111 0110 0101 0100 0011 0000 */

  printf("leastBitPos(0x%x) returns 0x%x.\n",inputval,leastBitPos(inputval));
  return 0;
}
  
