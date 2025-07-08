// UVA 455 - Periodic Strings
//
// 題目說明：
// 給一個非空字串 s，長度 ≤ 80，問它的「最小週期長度」是什麼？
// 也就是最短的長度 k，使得 s = t + t + ... + t（t 重複若干次，長度為 k）
//
// 解法：
// 使用 KMP 演算法中的 LPS（Longest Prefix Suffix）陣列
// - 若 lps[n-1] 是最後一個字元對應的 LPS 值
// - 那最短週期候選長度為 x = n - lps[n-1]
// - 若 n % x == 0 表示可以重複構成，x 為最小週期
// - 否則，最小週期就是字串長度 n 本身
//
// 輸入格式：
// 第一行為測資數量 t，接著每組測資前有一個空行
// 每組測資為一行字串（不含空白）
//
// 輸出格式：
// 每組輸出為一個整數（最小週期長度），組與組之間用空行隔開（最後一組後不加）
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  string blank;
  getline(cin, blank);

  bool first = true;
  while (t--) {
    if (!first)
      cout << '\n';
    getline(cin, blank);
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

    int x = n - lps[n - 1];
    if (n % x == 0)
      cout << x << '\n';
    else
      cout << n << '\n';
    first = false;
  }

  return 0;
}
