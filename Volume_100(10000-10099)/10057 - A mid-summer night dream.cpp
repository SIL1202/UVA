#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dream(int n) {
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  int m1 = arr[(n - 1) / 2];
  int m2 = arr[(n) / 2];

  int count = 0;
  for (int n : arr) {
    if (n >= m1 && n <= m2)
      count++;
  }

  int diff = m2 - m1 + 1;
  cout << m1 << " " << count << " " << diff << endl;
}
int main() {
  int n;
  while (cin >> n) {
    dream(n);
  }
  return 0;
}
