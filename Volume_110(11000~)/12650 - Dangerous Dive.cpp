#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, r;
  while (cin >> n >> r) {
    vector<int> v(r);
    for (int i = 0; i < r; i++) {
      cin >> v[i];
    }

    if (n == r) {
      cout << "*";
    } else {

      sort(v.begin(), v.end());

      int index = 0;
      for (int i = 1; i <= n; i++) {
        if (v[index] != i)
          cout << i << " ";
        else
          index++;
      }
    }
    cout << endl;
  }
  return 0;
}

// 1 3 5
// 1 3 4
//
// i = 3
// index = 2
// 2 4
