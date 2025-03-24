#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &number) {
  for (int &n : number) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
      if (n % i == 0) {
        sum += i;
      }
    }

    cout << setw(5) << n << "  ";
    if (sum == n)
      cout << "PERFECT\n";
    else if (sum > n)
      cout << "ABUNDANT\n";
    else
      cout << "DEFICIENT\n";
  }
}

int main() {
  int n;
  vector<int> number;

  while (cin >> n && n != 0) {
    number.push_back(n);
  }

  cout << "PERFECTION OUTPUT\n";
  solve(number);
  cout << "END OF OUTPUT\n";
  return 0;
}
