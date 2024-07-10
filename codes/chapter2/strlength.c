#include <stdio.h>
#include <string.h>

int strlonger(char *s, char *t) { 
  return ((int) (strlen(s) - strlen(t))) > 0; 
}

// int len(int a[]) { return sizeof(a) / sizeof(a[0]); }

int max(int a, int b) {
  int c[] = {a, b};
  int res = a - b < 0;
  return c[res];
}

int main(void) {
  char x[] = "Helll";
  char y[] = "Hi";

  int res = strlonger(x, y);
  printf("%d\n", res);
}
