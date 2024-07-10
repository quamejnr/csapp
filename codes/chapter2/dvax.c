#include <stdio.h>

// bis is the equivalent of OR
int bis(int x, int m) { return x | m; }

// bic is equivalent to x & ~m
int bic(int x, int m) {
  int y = x ^ m;
  return y & x;
}


int bool_or(int x, int y) {
  int result = bis(x, y);
  return result;
}

// x ^ y = (x & ~y) | (~x & y)
int bool_xor(int x, int y) {
  int result = bis(bic(x, y), bic(y, x));  
  return result;
}


int main(void) {
  printf("0x%X\n", bis(0xA6, 0xD5));
  printf("0x%X\n", bic(0xA6, 0xD5));
  printf("0x%X\n", bool_or(0xA6, 0xD5));
  printf("0x%X\n", bool_xor(0xA6, 0xD5));

}
