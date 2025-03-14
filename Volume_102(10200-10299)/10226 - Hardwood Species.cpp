#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  cin.ignore();
  bool first = true;
  while (n--) {
    if (!first)
      cout << endl;
    first = false;

    string s;
    map<string, int> mp;
    int count = 0;
    while (getline(cin, s)) {
      if (s.empty())
        break;
      mp[s]++;
      count++;
    }

    for (auto &[a, b] : mp) {
      cout << a << " ";
      cout << fixed << setprecision(4) << (b * 100.0 / count) << endl;
    }
  }
  return 0;
}
