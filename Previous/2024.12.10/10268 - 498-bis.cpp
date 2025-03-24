#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string s;
int x;
vector<int> v;

int main() {
  while (cin >> x) {
    getline(cin, s);
    getline(cin, s);
    // cout << "s: " << s << "\n";
    stringstream ss(s);
    v.clear();
    while (ss >> s) {
      v.push_back(stoi(s));
    }
    v.pop_back();
    reverse(v.begin(), v.end());
    long long mul = 1;
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
      // cout << "i: " << i << " " << v[i] << " " << ans << " " << mul << "\n";
      ans += v[i] * (i + 1) * mul;
      mul *= x;
    }
    cout << ans << "\n";
  }
}
