#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++)
    cin >> vec[i];
  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 1; j < n - i; j++) {
      if (vec[j - 1] > vec[j]) {
        swap(vec[j], vec[j - 1]);
        count++;
      }
    }
  }
  cout << "Optimal train swapping takes " << count << " swaps." << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
