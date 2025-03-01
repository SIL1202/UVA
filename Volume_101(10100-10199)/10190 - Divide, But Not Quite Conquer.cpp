#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n < 2 || m < 2) {
      cout << "Boring!\n";
      continue;
    }

    vector<long long> ans;
    ans.push_back(n);

    while (n != 1) {
      if (n % m == 0) {
        n /= m;
        ans.push_back(n);
      } else {
        cout << "Boring!\n";
        goto next_input;
      }
    }

    for (size_t i = 0; i < ans.size(); i++) {
      if (i > 0)
        cout << " ";
      cout << ans[i];
    }
    cout << endl;

  next_input:
    continue;
  }
  return 0;
}
