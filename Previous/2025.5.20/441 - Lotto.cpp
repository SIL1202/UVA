#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<int> &v, vector<int> &path, int start) {
  if (path.size() == 6) {
    for (int i = 0; i < 6; ++i) {
      if (i > 0)
        cout << ' ';
      cout << path[i];
    }

    cout << '\n';
  }

  for (int i = start; i < v.size(); ++i) {
    path.push_back(v[i]);
    dfs(v, path, i + 1);
    path.pop_back();
  }
}

int main() {
  int n;
  bool first = true;
  while (cin >> n && n != 0) {
    vector<int> vec(n);
    for (int &v : vec)
      cin >> v;

    if (!first)
      cout << "\n";
    first = false;

    vector<int> path;
    dfs(vec, path, 0);
  }

  return 0;
}
