#include <stdio.h>

void modificaInt(int *p) {
  *p = 10;
}

void modificaChar(char *p) {
  *p = 'b';
}

void modificaFloat(float *p) {
  *p = 10.25;
}

int main() {
  int n = 5, *p1 = NULL;
  char c = 'a', *p2 = NULL;
  float f = 5.25, *p3 = NULL;

  p1 = &n;
  p2 = &c;
  p3 = &f;

  printf("%d %c %.2f\n", n, c, f);
  modificaInt(p1);
  modificaChar(p2);
  modificaFloat(p3);
  printf("%d %c %.2f", n, c, f);

  return 0;
}