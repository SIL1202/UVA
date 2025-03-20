#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> mp;
void solve() {
  string country, name;
  cin >> country;
  getline(cin, name);
  mp[country]++;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  for (auto &[a, b] : mp) {
    cout << a << " " << b << endl;
  }

  return 0;
}
