// 題目：UVa 11452 - Dancing the Cheeky-Cheeky
// 給定一段舞步序列 s，裡面包含某個基本舞步 pattern 重複了至少兩次、不到三次
// 目標：找出 pattern，並根據目前舞步的長度 n，輸出接下來的 8 個舞步，並加上
// "..." 結尾 解法：使用 KMP 演算法建立 lps 陣列，計算最短重複單位的長度
// patternLen = n - lps[n - 1] 然後從位置 n 開始，模 pattern 長度補上 8
// 個字符，即可得到接下來的舞步
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> lps(n);
    for (int i = 1, j = 0; i < n;) {
      if (s[i] == s[j])
        lps[i++] = ++j;
      else
        j ? j = lps[j - 1] : lps[i++] = 0;
    }

    int len = n - lps[n - 1];
    string pattern = s.substr(0, len);

    for (int i = 0; i < 8; ++i)
      cout << pattern[(n + i) % len];

    cout << "...\n";
  }
  return 0;
}
