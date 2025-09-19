#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int index;
  int cnt;
} Node;

int cmp(const void *a, const void *b) {
  const Node x = *(const Node *)a;
  const Node y = *(const Node *)b;
  if (x.cnt != y.cnt)
    return y.cnt - x.cnt;
  return x.index - y.index;
}

int main() {
  int n;
  scanf("%d\n", &n);

  Node letters[26] = {0};
  for (int i = 0; i < 26; ++i)
    letters[i].index = i;

  while (n--) {
    char line[1024];
    fgets(line, sizeof(line), stdin);

    for (int i = 0; line[i]; ++i) {
      if (isalpha(line[i])) {
        char up = toupper(line[i]);
        ++letters[up - 'A'].cnt;
      }
    }
  }

  qsort(letters, 26, sizeof(letters[0]), cmp);

  for (int i = 0; i < 26; ++i) {
    if (letters[i].cnt > 0)
      printf("%c %d\n", letters[i].index + 'A', letters[i].cnt);
  }
  return 0;
}
/*
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  vector<pair<int, int>> node(26, make_pair(0, 0)); // {index, cnt}
  for (int i = 0; i < 26; ++i)
    node[i].first = i;

  while (n--) {
    string line;
    getline(cin, line);
    for (char c : line) {
      if (isalpha(c)) {
        char up = toupper(c);
        ++node[up - 'A'].second;
      }
    }
  }

  sort(node.begin(), node.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         if (a.second != b.second)
           return a.second > b.second;
         return a.first < b.first;
       });

  for (auto &p : node) {
    if (p.second > 0)
      cout << (char)(p.first + 'A') << " " << p.second << '\n';
  }

  return 0;
}
*/
