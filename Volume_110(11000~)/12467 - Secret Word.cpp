/*
 題目目標：
找出最長的子字串 W，使得：
1. W 是原字串 s 的某段 substring。
2. reverse(W) 是 s 的 prefix（即 s 開頭的部分）。

 解法核心：
使用「二分搜尋」來猜測 W 的可能長度 m。
- 每次取 s 的前 m 個字元，reverse 後叫做 rev。
- 用 KMP 演算法檢查 rev 是否存在於 s 中（通常會在最開頭）。
- 如果 match，代表這段長度可行，試著再試更長的 m。
- 如果不行，就試更短。

 初始化邏輯：
- l = 1：因為 W 是「非空」子字串，不能是 0。
- r = s.length()：最長可能是整個 s。

 時間複雜度：
- 二分搜尋：logN 次
- 每次 KMP：O(N)
- 整體時間：O(N log N)
*/

#include <iostream>
#include <vector>
using namespace std;

bool match(string &s, string &p) {
  int n = s.length(), m = p.length();
  vector<int> lps(m);
  for (int i = 1, j = 0; i < m;) {
    if (p[i] == p[j])
      lps[i++] = ++j;
    else
      j ? j = lps[j - 1] : lps[i++] = 0;
  }

  for (int i = 0, j = 0; i < n;) {
    if (s[i] == p[j]) {
      ++i, ++j;
      if (j == m)
        return true;
    } else if (i < n && s[i] != p[j])
      j ? j = lps[j - 1] : ++i;
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int n = s.length();
    int l = 1, r = n;

    string ans = "";
    while (l <= r) {
      int mid = l + ((r - l) >> 1);

      string rev = "";
      for (int i = mid - 1; i >= 0; --i)
        rev += s[i]; // reverse string

      if (match(s, rev)) {
        ans = rev;
        l = mid + 1;
      } else
        r = mid - 1;
    }

    cout << ans << '\n';
  }
  return 0;
}
