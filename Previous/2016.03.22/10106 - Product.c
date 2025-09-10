#include <stdio.h>
#include <string.h>

#define MAX 10000
int main() {
  char a[MAX], b[MAX];
  memset(a, '0', MAX);
  memset(b, '0', MAX);
  while (scanf("%s %s", a, b) == 2) {
    int x[MAX] = {0}, y[MAX] = {0};
    int s[MAX] = {0};
    int al = strlen(a), bl = strlen(b);
    for (int i = 0; i < al; ++i)
      x[i] = a[al - i - 1] - '0';
    for (int i = 0; i < bl; ++i)
      y[i] = b[bl - i - 1] - '0';

    for (int i = 0; i < al; ++i)
      for (int j = 0; j < bl; ++j) {
        s[i + j] += x[i] * y[j];
        s[i + j + 1] += s[i + j] / 10;
        s[i + j] = s[i + j] % 10;
      }

    int k = 0;
    for (int i = al + bl; i >= 0; --i) {
      if (s[i] != 0)
        k = 1;
      if (k)
        printf("%d", s[i]);
    }
    if (!k)
      printf("0");
    puts("");
  }
  return 0;
}

//  122
// 2212
//  ---
//  244
// 122
