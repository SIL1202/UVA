#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);

  printf("Lumberjacks:\n");
  int arr[10];
  while (t--) {
    for (int i = 0; i < 10; ++i)
      scanf("%d", &arr[i]);

    char up = 1, down = 1;
    for (int i = 0; i < 9; ++i) {
      if (arr[i] < arr[i + 1])
        down = 0;
      if (arr[i] > arr[i + 1])
        up = 0;
    }

    if (up || down)
      printf("Ordered\n");
    else
      printf("Unordered\n");
  }

  return 0;
}
