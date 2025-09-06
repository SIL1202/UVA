#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    int n;
    scanf("%d", &n);

    int arr[50];
    for (int i = 0; i < n; ++i)
      scanf("%d", &arr[i]);

    int h, l;
    h = l = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (arr[i + 1] > arr[i])
        ++h;
      else if (arr[i + 1] < arr[i])
        ++l;
    }

    printf("Case %d: %d %d\n", i, h, l);
  }

  return 0;
}
