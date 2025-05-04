// uva10327
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (auto &v : a)
      cin >> v;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        ans += (a[i] > a[j]);
      }
    }
    cout << "Minimum exchange operations : " << ans << endl;
  }
  return 0;
}
