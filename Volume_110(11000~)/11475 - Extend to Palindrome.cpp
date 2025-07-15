// Extend to Palindrome: 使用 KMP LPS 找 rev + "$" + x 最長前後綴
// 題目：給一個字串，最少補在尾巴的字使其變成回文
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string KMP(string x) {
  string rev = x;
  reverse(rev.begin(), rev.end());
  string s = rev + "$" + x; // reverse first

  int n = s.length();
  vector<int> lps(n);

  for (int i = 1, j = 0; i < n;) {
    if (s[i] == s[j])
      lps[i++] = ++j;
    else
      j ? j = lps[j - 1] : lps[i++] = 0;
  }

  int overlap = lps[n - 1];
  return x + rev.substr(overlap); // + start from the overlap
}

int main() {
  string s;
  while (cin >> s) {
    cout << KMP(s) << '\n';
  }
  return 0;
}

// lanacanalpanama + $ + amanaplanacanal
// amanaplanacanal + panama
