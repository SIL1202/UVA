#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string a, b;
  while (cin >> a >> b) {
    if (a == "0" || b == "0") {
      cout << "0\n";
      continue;
    }

    vector<int> r(a.size() + b.size(), 0);

    for (int i = a.size() - 1; i >= 0; i--)
      for (int j = b.size() - 1; j >= 0; j--)
        r[i + j + 1] += (a[i] - '0') * (b[j] - '0');

    // 處理進位
    for (int k = r.size() - 1; k > 0; k--) {
      r[k - 1] += r[k] / 10;
      r[k] %= 10;
    }

    // 去掉前導 0
    int i = 0;
    while (i < r.size() - 1 && r[i] == 0)
      i++;

    for (; i < r.size(); i++)
      cout << r[i];
    cout << '\n';
  }
} // void solve(string x, string y) {
//   vector<vector<int>> a(x.size());
//   vector<int> ans;
//
//   for (int i = x.size() - 1; i >= 0; i--) {
//     int carry = 0;
//     for (int j = y.size() - 1; j >= 0; j--) {
//       int s = carry + (x[i] - '0') * (y[j] - '0');
//       a[x.size() - i - 1].push_back(s % 10);
//       carry = s / 10;
//     }
//     if (carry)
//       a[x.size() - i - 1].push_back(carry);
//     if (i > 0)
//       a[x.size() - i].assign(x.size() - i, 0);
//   }
//
//   /* for (int i = 0; i < a.size(); i++) {
//     for (int j = 0; j < a[i].size(); j++) {
//       cout << a[i][j];
//     }
//     cout << endl;
//   } */
//
//   int carry = 0;
//   for (int i = 0; i < a[a.size() - 1].size(); i++) {
//     int sum = carry;
//     for (int j = 0; j < a.size(); j++) {
//       if (i < a[j].size())
//         sum += a[j][i];
//     }
//     ans.push_back(sum % 10);
//     carry = sum / 10;
//   }
//   if (carry)
//     ans.push_back(carry);
//
//   // 移除前導零
//   int n = ans.size();
//   while (n > 1 && ans[n - 1] == 0) {
//     ans.pop_back();
//     n--;
//   }
//
//   reverse(ans.begin(), ans.end());
//   for (int c : ans)
//     cout << c;
// }
// /*
// 2222
//   12
// ----
// 4444
// 222
// ----
// 6664
//
//  122
//  2255
//  5555
//  ----
// 10275
//  */
// int main() {
//   string x, y;
//   while (cin >> x >> y) {
//     solve(x, y);
//     cout << endl;
//   }
//   return 0;
// }
