#include <stdio.h>
#include <stdlib.h>

int div16(int val) {
  int bias = val << 31 & 0xf;
  return (val + bias) >> 4;
}

int main(int argc, char *argv[]) {
  int num = atoi(argv[1]);
  printf("%d\n", div16(num));
}
