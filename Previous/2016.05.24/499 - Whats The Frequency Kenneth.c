#include <stdio.h>
#define max(a, b) ((a > b) ? (a) : (b))

int main(void) {
  char line[10005];
  size_t len = 0;
  while (fgets(line, sizeof(line), stdin)) {
    int up[26] = {0}, lo[26] = {0};

    for (char *p = line; *p; ++p)
      if (*p >= 'A' && *p <= 'Z')
        ++up[*p - 'A'];
      else if (*p >= 'a' && *p <= 'z')
        ++lo[*p - 'a'];

    int maxf = 0;
    for (int i = 0; i < 26; ++i) {
      maxf = max(maxf, up[i]);
      maxf = max(maxf, lo[i]);
    }

    for (int i = 0; i < 26; ++i)
      if (up[i] == maxf)
        putchar('A' + i);
    for (int i = 0; i < 26; ++i)
      if (lo[i] == maxf)
        putchar('a' + i);

    printf(" %d\n", maxf);
  }
  return 0;
}

// C++ approach:
//
// #include <algorithm>
// #include <cctype>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
//
// int main() {
//   string line = "";
//   while (getline(cin, line)) {
//     vector<int> up(26), low(26);
//
//     for (char c : line)
//       if (isupper(c))
//         ++up[c - 'A'];
//       else if (islower(c))
//         ++low[c - 'a'];
//
//     int maxf = 0;
//     for (int i = 0; i < 26; ++i) {
//       maxf = max(up[i], maxf);
//       maxf = max(low[i], maxf);
//     }
//
//     for (int i = 0; i < 26; ++i)
//       if (up[i] == maxf)
//         cout << (char)(i + 'A');
//     for (int i = 0; i < 26; ++i)
//       if (low[i] == maxf)
//         cout << (char)(i + 'a');
//
//     cout << ' ' << maxf << '\n';
//   }
//   return 0;
// }
