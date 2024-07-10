#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

void show_int(int x) {
  printf("int\t");
  show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x) {
  printf("float\t");
  show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x) {
  printf("int *\t");
  show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float)ival;
  int *pval = &ival;
  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}

int main(int argc, char *argv[]) {
  // int val = atoi(argv[1]);
  // int a = 0x12345678;
  // byte_pointer ap = (byte_pointer) &a;
  const char *m = "mnopqr";
  show_bytes((byte_pointer)m, strlen(m) + 1);

  // show_bytes(ap, 1);
  // show_bytes(ap, 2);
  // show_bytes(ap, 3);
  // test_show_bytes(val);
}
