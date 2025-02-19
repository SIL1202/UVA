#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int Max = 0;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    Max = max(Max, vec[i]);
  }

  vector<int> fi{1, 2};
  while (fi.back() <= Max) {
    fi.push_back(fi.back() + fi[fi.size() - 2]);
  }

  for (int i = 0; i < vec.size(); i++) {
    int number = vec[i];
    cout << number << " = ";
    bool flag = 0;
    for (int f = fi.size() - 1; f >= 0; f--) {
      if (number >= fi[f]) {
        number = number - fi[f];
        cout << 1;
        flag = true;
      } else if (flag && number < fi[f])
        cout << 0;
    }
    cout << " (fib)\n";
  }
  return 0;
}
