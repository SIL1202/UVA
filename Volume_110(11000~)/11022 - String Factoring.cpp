// UVA 11022 - String Factoring
// ---------------------------------------------------
// 題目目標：
//   對每個字串進行「最大化壓縮」（maximal factoring）
//   並求出壓縮後的最小 weight（只算實際字母，不算括號與次方）
//
// 主要做法：動態規劃 + KMP（LPS）前處理
//
// dp[i][j] 表示：
//   對子字串 s[i..j] 進行所有可能壓縮後，最小的 weight 值
//
// 狀態轉移：
//   1. 嘗試從中間 k 切開為左右兩段：
//        dp[i][j] = min(dp[i][k] + dp[k+1][j])
//   2. 嘗試將 s[i..j] 看成某個 pattern 重複多次：
//        若 len % patternLen == 0，則
//        dp[i][j] = min(dp[i][j], dp[i][i + patternLen - 1])
//
// KMP 的關鍵：
//   lps[len - 1] 表示整段 s[i..j] 的最長 border 長度（前綴 = 後綴）
//   patternLen = len - lps[len - 1] 是最短可重複 pattern 的長度
// ---------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  while (cin >> s && s != "*") {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 初始化 dp[i][i]：單一字元最小 weight 為 1
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }

    // 枚舉區間長度 len
    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        dp[i][j] = len; // 最壞情況：不壓縮，整段原樣

        // 嘗試斷開為兩部分
        for (int k = i; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }

        string t = s.substr(i, len);
        vector<int> lps(len);
        for (int x = 1, y = 0; x < len;) {
          if (t[x] == t[y])
            lps[x++] = ++y;
          else
            y ? y = lps[y - 1] : lps[x++] = 0;
        }

        int border = lps[len - 1]; // 最長前後綴相等長度
        int patternLen = len - border;

        if (len % patternLen == 0) {
          dp[i][j] = min(dp[i][j], dp[i][i + patternLen - 1]);
        }
      }
    }

    cout << dp[0][n - 1] << '\n';
  }
  return 0;
}
