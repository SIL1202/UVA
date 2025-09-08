#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int ch;
  int freq;
} Node;

static int cmp(const void *a, const void *b) {
  const Node *x = (const Node *)a;
  const Node *y = (const Node *)b;
  if (x->freq != y->freq)
    return x->freq - y->freq;
  return y->ch - x->ch;
}

int main(void) {
  char *line = NULL;
  size_t cap = 0;
  ssize_t nread;
  int first = 1;

  while ((nread = getline(&line, &cap, stdin)) != -1) {
    int cnt[256] = {0};

    for (ssize_t i = 0; i < nread; ++i) {
      unsigned char c = (unsigned char)line[i];
      if (c == '\n' || c == '\r')
        continue;
      cnt[c]++;
    }

    Node arr[256];
    int n = 0;
    for (int c = 0; c < 256; ++c) {
      if (cnt[c]) {
        arr[n].ch = c;
        arr[n].freq = cnt[c];
        ++n;
      }
    }

    qsort(arr, n, sizeof arr[0], cmp);

    if (!first)
      puts("");
    first = 0;

    for (int i = 0; i < n; ++i)
      printf("%d %d\n", arr[i].ch, arr[i].freq);
  }

  free(line);
  return 0;
}
