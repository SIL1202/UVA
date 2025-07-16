// using trie to find the the max of (length of common prefix) * (numbers of
// strings)
#include <iostream>
using namespace std;

class Trie {
private:
  Trie *child[2];
  int cnt;

public:
  Trie() {
    child[0] = child[1] = nullptr;
    cnt = 0;
  }

  void insert(string s) {
    Trie *root = this;
    for (char c : s) {
      int i = c - '0';
      if (!root->child[i])
        root->child[i] = new Trie();
      root = root->child[i];
      ++root->cnt;
    }
  }

  void dfs(int d, int &mx) {
    mx = max(mx, d * cnt);
    for (int i = 0; i < 2; ++i)
      if (child[i])
        child[i]->dfs(d + 1, mx);
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Trie root;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      root.insert(s);
    }
    int mx = 0;
    root.dfs(0, mx);
    cout << mx << '\n';
  }
}
