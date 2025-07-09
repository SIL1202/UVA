// 題目：UVa 12604 - Caesar Cipher
// 題意：給定一個自訂字母表 A、一個明文片段 W，以及加密後的訊息 S，
//      已知 S 是用 Caesar Cipher（位移加密）加密而成，請找出可能的位移量
//      sh，使得 將 S 解密後，恰好只出現一次明文 W。
//
// Caesar Cipher：每個字元往後位移 sh 個位置（可循環），根據自訂字母表 A 排序。
// 限制條件：0 ≤ sh < |A|，W 只會出現一次，可能有多個 sh 符合條件。
//
// 解法：
// 1️⃣ 建立 A 的位置表（pos[]），快速找出 S 中每個字元的原始位置。
// 2️⃣ 檢查 S 中是否存在不在 A 中的字元，若有則無法解密（直接輸出 no solution）。
// 3️⃣ 對每個可能的 shift 值 sh，嘗試將 S 解密，並用 KMP 檢查是否只出現一次 W。
// 4️⃣ 使用 LPS（KMP 前處理）加速查詢 W 在解密後的 S 中出現的次數。
// 5️⃣ 最後根據符合條件的 sh 個數輸出：
//     - 無符合：no solution
//     - 唯一解：unique: sh
//     - 多重解：ambiguous: sh1 sh2 ...
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string A, W, S;
    cin >> A >> W >> S;

    int s_len = S.length(), w_len = W.length();
    int a_len = A.length();

    // build shifted table
    int pos[128];
    fill(begin(pos), end(pos), -1);
    for (int i = 0; i < a_len; ++i)
      pos[A[i]] = i;

    bool valid_input = true;
    for (char c : S) {
      if (pos[c] == -1) {
        valid_input = false;
        break;
      }
    }
    if (!valid_input) {
      cout << "no solution\n";
      continue;
    }

    // build LPS table
    vector<int> lps(w_len);
    for (int i = 1, j = 0; i < w_len;) {
      if (W[i] == W[j])
        lps[i++] = ++j;
      else
        j ? j = lps[j - 1] : i++;
    }

    vector<int> valid_shifts;
    for (int sh = 0; sh < a_len; ++sh) {
      int cnt = 0;

      // KMP algorithm
      for (int i = 0, j = 0; i < s_len;) {
        int idx = (pos[S[i]] - sh) % a_len;
        if (idx < 0)
          idx += a_len;
        char dc = A[idx];

        if (dc == W[j]) {
          ++i, ++j;
          if (j == w_len) {
            ++cnt;
            j = lps[j - 1];
          }
        } else {
          j ? j = lps[j - 1] : ++i;
        }
      }

      if (cnt == 1)
        valid_shifts.push_back(sh);
    }

    // output results
    if (valid_shifts.empty())
      cout << "no solution\n";
    else if (valid_shifts.size() == 1)
      cout << "unique: " << valid_shifts[0] << '\n';
    else {
      sort(valid_shifts.begin(), valid_shifts.end());
      cout << "ambiguous:";
      for (int v : valid_shifts)
        cout << ' ' << v;
      cout << '\n';
    }
  }

  return 0;
}
