#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int cost(vector<int> &ink, string &base) {
  int Cost = 0;
  for (char &c : base) {
    Cost += ink[digits.find(c)];
  }
  return Cost;
}

string decimalToAny(int x, int base) {

  string any = "";

  while (x != 0) {
    any = digits[x % base] + any;
    x /= base;
  }
  return any;
}

void solve() {
  vector<int> ink(36);
  for (int i = 0; i < 36; i++) {
    cin >> ink[i];
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n;
    cin >> n;
    int Min = INT_MAX;
    map<int, int> base_ink;
    for (int base = 2; base <= 36; base++) {
      string value = decimalToAny(n, base);
      base_ink[base] = cost(ink, value);
      Min = min(Min, base_ink[base]);
    }

    cout << "Cheapest base(s) for number " << n << ": ";
    bool first = 1;
    for (auto mp : base_ink) {
      if (mp.second == Min) {
        if (!first)
          cout << " ";

        cout << mp.first;
        first = 0;
      }
    }
    cout << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << "Case " << i + 1 << ":\n";
    solve();
    if (i != t - 1)
      cout << endl;
  }
  return 0;
}
