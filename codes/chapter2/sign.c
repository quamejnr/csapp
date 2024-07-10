#include "endian.h"
#include <stdio.h>

void sign_extension() {
  short sx = -12345;
  unsigned short usx = sx;

  int x = sx;
  unsigned ux = usx;

  printf("sx = %d:\t", sx);
  show_bytes((byte_pointer)&sx, sizeof(short));
  printf("usx = %u:\t", usx);
  show_bytes((byte_pointer)&usx, sizeof(unsigned short));
  printf("x = %d:\t", x);
  show_bytes((byte_pointer)&x, sizeof(int));
  printf("ux = %u:\t", ux);
  show_bytes((byte_pointer)&ux, sizeof(unsigned));

  unsigned vx = sx;
  printf("vx = %u:\t", ux);
  show_bytes((byte_pointer)&ux, sizeof(unsigned));
}

int fun1(unsigned word) { return (int)((word << 24) >> 24); }

int fun2(unsigned word) { return ((int) word << 24) >> 24; }

int main(void) {
  int y = 0x000000C9;
  int x = fun1(y);
  printf("val: %d, hex: %.2x\n", x, x);

}
