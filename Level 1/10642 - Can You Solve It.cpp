#include <iostream>
using namespace std;

// 在第 k = x+y 條對角線上，
// 該對角線第一個原點的步數為 k(k+1)/2，
// 原點在該對角線上的第 x 位置。
//
// 0 0
// 0 1
// 1 0
// 0 2
// 1 1
// 2 0
// 0 3
// 2 1
// 1 2
// 3 0
// 0 4
// 3 1
// 2 2
// 1 3
// 4 0

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long a, b, a1, b1;
    cin >> a >> b >> a1 >> b1;
    long long end =
        (a1 + b1) * (a1 + b1 + 1) / 2 + a1; // 從 0, 0 到 end 點上走的步數
    long long begin =
        (a + b) * (a + b + 1) / 2 + a; //  // 從 0, 0 到 begin 點上走的步數
    long long ans = end - begin;
    cout << "Case " << i + 1 << ": " << ans << endl;
  }
  return 0;
}
