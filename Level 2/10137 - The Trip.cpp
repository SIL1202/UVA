#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
  vector<int> cents(n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    double val;
    cin >> val;
    cents[i] = round(val * 100); // 1501 = 1500.999999...
    // cout << "cents = " << cents[i] << endl;
    total += cents[i];
  }

  int avg = total / n;
  int remainder = total % n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (cents[i] > avg + (remainder > 0 ? 1 : 0)) {
      ans += cents[i] - (avg + (remainder > 0 ? 1 : 0));
      remainder--;
    }
  }
  cout << "$" << fixed << setprecision(2) << (ans / 100.0) << endl;
}

int main() {
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    solve(n);
  }
  return 0;
}
