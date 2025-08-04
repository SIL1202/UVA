#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  size_t t = 0;
  while (cin >> n) {
    bool is_B2 = true;
    vector<int> vec(n);
    for (int &v : vec) {
      cin >> v;
      if (v < 1)
        is_B2 = false;
    }

    bool exist[20001] = {false};
    for (int i = 1; i < n; ++i)
      if (vec[i] <= vec[i - 1])
        is_B2 = false;

    for (int i = 0; i < n && is_B2; ++i)
      for (int j = i; j < n; ++j) {
        int sum = vec[i] + vec[j];
        if (exist[sum])
          is_B2 = false;
        exist[sum] = true;
      }

    cout << "Case #" << ++t << ": It is " << (is_B2 ? "" : "not ")
         << "a B2-Sequence.\n\n";
  }
  return 0;
}
