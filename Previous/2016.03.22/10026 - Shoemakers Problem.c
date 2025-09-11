#include <stdio.h>
#include <stdlib.h>
#define ll long long

typedef struct pair {
  int id;
  ll d, p;
} pair;

int cmp(const void *a, const void *b) {
  const pair *x = (const pair *)a;
  const pair *y = (const pair *)b;

  __int128 lhs = (__int128)x->p * (__int128)y->d;
  __int128 rhs = (__int128)y->p * (__int128)x->d;

  if (lhs < rhs)
    return 1;
  if (lhs > rhs)
    return -1;
  return x->id > y->id;
}

int main() {
  int t;
  if (scanf("%d", &t) != 1)
    return 0;
  while (t--) {
    int n;
    scanf("%d", &n);
    pair *p = (pair *)malloc(sizeof(pair) * n);
    if (!p)
      return 0;

    for (int i = 0; i < n; ++i)
      scanf("%lld %lld", &p[i].d, &p[i].p), p[i].id = i + 1;

    qsort(p, n, sizeof(p[0]), cmp);

    for (int i = 0; i < n; ++i) {
      if (i)
        putchar(' ');
      printf("%d", p[i].id);
    }
    putchar('\n');
    free(p);
  }
  return 0;
}
