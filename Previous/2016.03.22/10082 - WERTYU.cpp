#include <iostream>
#include <string>
using namespace std;

int main() {
  const string keys = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

  unsigned char map[256] = {0};
  for (int i = 1; i < keys.size(); ++i)
    map[(unsigned char)keys[i]] = (unsigned char)keys[i - 1];

  string line;
  while (getline(cin, line)) {
    for (char c : line) {
      if (c == ' ')
        cout << ' ';
      else
        cout << map[(unsigned char)c];
    }
    cout << '\n';
  }
  return 0;
}
