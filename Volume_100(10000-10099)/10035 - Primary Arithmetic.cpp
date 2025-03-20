#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve(long long a, long long b) {
  vector<int> A, B;
  while (a != 0) {
    A.push_back(a % 10);
    a /= 10;
  }
  while (b != 0) {
    B.push_back(b % 10);
    b /= 10;
  }
  int count = 0;
  int n = max(A.size(), B.size());
  A.resize(n, 0);
  B.resize(n, 0);
  int x = 0;
  bool carry = false;

  for (int i = 0; i < n; i++) {
    x = A[i] + B[i];
    if (carry)
      x += 1;
    if (x > 9) {
      count++;
      carry = true;
      continue;
    }
    carry = false;
  }
  if (count == 0)
    cout << "No carry operation.\n";
  else if (count == 1)
    cout << "1 carry operation.\n";
  else
    cout << count << " carry operations.\n";
}

int main() {
  long long a, b;
  while (cin >> a >> b) {
    if (a == 0 && b == 0)
      break;
    solve(a, b);
  }
  return 0;
}
