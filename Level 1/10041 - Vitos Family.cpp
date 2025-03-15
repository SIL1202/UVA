#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int r;
  cin >> r;
  vector<int> relatives(r);
  for (int i = 0; i < r; i++) {
    cin >> relatives[i];
  }
  int Min = 30001;
  sort(relatives.begin(), relatives.end());

  int mid = relatives[r / 2];
  int sum = 0;
  for (int j = 0; j < r; j++) {
    sum += abs(mid - relatives[j]);
  }

  cout << sum << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
