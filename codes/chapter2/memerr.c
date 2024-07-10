#include <stdio.h>

int sum_elements(int a[], int length) {
  int i;
  int result = 0;

  for (i = 0; i < length - 1; i++) {
    printf("%d, %u, %d\n", i, length - 1, a[i]);
    result += a[i];
  }
  return result;
}

int main(void) {
  int numbers[3] = {1, 3, 4};

  int length = 3;
  int res;
  res = sum_elements(numbers, 0);
  printf("%d\n", res);

}
