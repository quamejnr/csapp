#include <stdio.h>
//
// int sum(int x, int y) { return x + y; }
//
void inplace_swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

void reverse_array(int a[], int len) {
  for (int i = 0; i < --len; i++) {
    inplace_swap(&a[i], &a[len]);
  }
}



int main(void) {
  // int x = 10;
  // int y = 5;
  //
  // printf("mem:%p, val:%d\n", &y, y);
  // printf("mem:%p, val:%d\n", &x, x);
  // y = x ^ y;
  // printf("First operation");
  // printf("mem:%p, val:%d\n", &y, y);
  // printf("mem:%p, val:%d\n", &x, x);
  // x = x ^ y;
  // printf("Second operation");
  // printf("mem:%p, val:%d\n", &y, y);
  // printf("mem:%p, val:%d\n", &x, x);
  // y = x ^ y;
  // printf("Third operation");
  // printf("mem:%p, val:%d\n", &y, y);
  // printf("mem:%p, val:%d\n", &x, x);
  //
  // Swapping
  // int x;
  // x = 15;
  // y= &x;

  // inplace_swap(&x, &x);

  // printf("%d\n", x);
  // printf("%d\n", x);

  // typecasting
  int x = 15;
  float f = 2.5;
  f *= x;
  float f = * (float *) &x;
  float y = (float) x;
  
  // int i = 33000;
  // short s = i;
  // printf("%hd", s);
  // printf("%f", y);
  // printf("%f\n", x*2);
  // printf("%f\n", f);
  // printf("%c\n", y);
  //
  int a[] = {1, 2, 3, 4, 5};
  int len = sizeof(a) / sizeof(a[0]);

  reverse_array(a, len);
  for (int i = 0; i < len; i++) {
    printf("%d", a[i]);
  }
  // printf("0x%X\n", 0x87654321 & 0xFF);
  // printf("0x%X\n", 0x87654321 ^ 0xFFFFFF00);
  // printf("0x%X\n", 0x87654321 | 0xFF);
  // int x, y;
  // x = 0x69;
  // y = 0x55;
  // printf("%X", (x&&y));
}
