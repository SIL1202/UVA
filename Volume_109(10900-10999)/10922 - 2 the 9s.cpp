#include <iostream>
#include <string>
using namespace std;

int recur(const string &s, int count = 1) {
  int num = 0;
  for (char c : s) {
    num += c - '0';
  }
  if (num % 9 != 0)
    return 0;
  if (num < 10)
    return count;
  return recur(to_string(num), count + 1);
}

int main() {
  string s;
  while (cin >> s) {
    if (s == "0")
      break;

    int n = recur(s);
    // cout << "n = " << n << endl;
    if (n == 0) {
      cout << s << " is not a multiple of 9.\n";
    } else {
      cout << s << " is a multiple of 9 and has 9-degree " << n << ".\n";
    }
  }
  return 0;
}
