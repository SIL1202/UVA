#include <stdio.h>
#include <stdlib.h>

int is_sym(long long **a, int n) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (a[i][j] < 0)
        return 0;
      else if (a[i][j] != a[n - 1 - i][n - 1 - j])
        return 0;
  return 1;
}

int main(void) {
  int t;
  if (scanf("%d", &t) != 1)
    return 0;

  for (int t_i = 0; t_i < t; ++t_i) {
    int n;
    scanf(" N = %d", &n);

    long long **a = (long long **)malloc(n * sizeof(*a));
    for (int i = 0; i < n; ++i)
      a[i] = (long long *)malloc(n * sizeof(long long));

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        scanf("%lld", &a[i][j]);

    printf("Test #%d: %symmetric.\n", t_i + 1, is_sym(a, n) ? "S" : "Non-s");
    for (int i = 0; i < n; ++i)
      free(a[i]);
    free(a);
  }
  return 0;
}
