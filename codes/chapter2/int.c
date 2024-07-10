// #include <cinttypes>
// #include <cinttypes>
// #include <stdio.h>
// #include <limits.h>
// #include <stdint.h>
//
// short x = 12345;
// short mx = -x;
//
// int main(void) {
//   show_bytes
// }


// #include <stdio.h>

void hello(int);

int	printf(const char * __restrict, ...) __printflike(1, 2);

int main(void) {
  hello(5);
}

void hello(int num) {
  printf("Number : %d", num);

}

