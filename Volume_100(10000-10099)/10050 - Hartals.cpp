#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int days;
  cin >> days;
  int p;
  cin >> p;
  vector<bool> party(days + 1, false);
  int count = 0;
  int x;

  for (int i = 0; i < p; i++) {
    int hartal;
    cin >> hartal;
    x = hartal;
    while (x <= days) {
      if (party[x] == false && x % 7 != 6 && x % 7 != 0) {
        party[x] = true;
        // cout << "x = " << x << " ";
        count++;
      }
      x += hartal;
    }
    // cout << endl;
  }
  cout << count << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}
