#include <stdio.h>

int main(void) {
  int a, b;
  while (scanf("%d %d", &a, &b) == 2) {
    printf("[%d;", a / b);
    while (b != 1) {
      int tmp = a % b;
      if (tmp != 1) {
        a = b;
        b = tmp;
        printf("%d,", a / b);
      } else {
        printf("%d]\n", b);
        break;
      }
    }
  }
  return 0;
}
