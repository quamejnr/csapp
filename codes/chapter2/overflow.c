#include <limits.h>
#include <stdio.h>

int uadd_ok(unsigned x, unsigned y) {
  // Not 0 will flip all the bits to 1 since they are all 0.
  unsigned overflow = ~0U;
  int sum = x + y;

  // unsigned values can cause overflow if x + y >= x
  return sum >= x;
}

int tadd_ok(int x, int y) {
  // An overflow can occur in two situations
  // 1. If x and y are both greater than 0 but their sum is less than 0
  // 2. If x and y are both less than 0 but their sum is greater than 0
  int pos_overflow = (x > 0 && y > 0) && x + y <= 0;
  int neg_overflow = (x < 0 && y < 0) && x + y >= 0;
  return !(pos_overflow || neg_overflow);
}

int main(void) {
  unsigned x = UINT_MAX;
  unsigned y = 2;
  int v = INT_MAX - 2;
  int w = INT_MAX;

  int s = INT_MIN + 5;
  int t = INT_MIN + 10;

  printf("%d\n", uadd_ok(x, y));
  printf("%d\n", tadd_ok(s, t));
}
