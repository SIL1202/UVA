#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  bool first = true;
  while (getline(cin, s)) {
    vector<pair<int, int>> vec(128, {0, 0});
    for (char &c : s) {
      vec[c].first = c;
      vec[c].second++;
    }
    sort(vec.begin(), vec.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           if (a.second == b.second)
             return a.first > b.first;
           return a.second < b.second;
         });

    if (!first)
      cout << endl;
    for (auto v : vec) {
      if (v.second > 0)
        cout << v.first << " " << v.second << endl;
    }
    first = false;
  }

  return 0;
}
