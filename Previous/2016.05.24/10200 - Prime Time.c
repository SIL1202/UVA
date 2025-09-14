#include <stdio.h>

#define UPPER 10001
#define eps 1e-12

static int prefix[UPPER];

static int prime(long long n) {
  if (n < 2)
    return 0;
  if ((n & 1) == 0)
    return n == 2;
  for (long long d = 3; d * d <= n; d += 2)
    if (n % d == 0)
      return 0;
  return 1;
}

int main(void) {
  // n=0 時 0^2+0+41=41 是質數
  prefix[0] = 1;
  for (int i = 1; i < UPPER; ++i) {
    long long v = 1LL * i * i + i + 41;
    prefix[i] = prefix[i - 1] + (prime(v) ? 1 : 0);
  }

  int a, b;
  while (scanf("%d %d", &a, &b) == 2) {
    int total = b - a + 1;
    int cnt = prefix[b] - (a ? prefix[a - 1] : 0);
    double per = 100.0 * cnt / total;
    printf("%.2f\n", per + eps);
  }
  return 0;
}
