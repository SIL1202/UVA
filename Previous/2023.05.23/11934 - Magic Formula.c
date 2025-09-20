#include <stdio.h>
#define ll long long

ll func(int a, int b, int c, int x) { return a * x * x + b * x + c; }

int main() {
  int a, b, c, d, l;
  while (scanf("%d%d%d%d%d", &a, &b, &c, &d, &l)) {
    if (a == b && b == c && c == d && d == l)
      break;
    int cnt = 0;
    for (int i = 0; i <= l; ++i) {
      if (func(a, b, c, i) % d == 0)
        ++cnt;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
