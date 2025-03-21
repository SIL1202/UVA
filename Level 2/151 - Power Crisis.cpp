#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
  for (int m = 1; m <= n; m++) {
    int j = 1;
    vector<int> cache(n + 1);
    cache[0] = 1;
    vector<bool> region(n + 1, false);
    int count = 0;
    cout << "m = " << m << endl;
    for (int i = 1; i <= n; i++) {
      if (i > n)
        i %= n;

      if (!region[i]) {
        count++;
      }
      if (count == m) {
        cout << i << " ";
        cache[j] = i;
        count = 0;
      }
    }

    cout << endl;
    if (cache[n - 1] == 13)
      cout << m << " ";
  }
  cout << endl;
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
