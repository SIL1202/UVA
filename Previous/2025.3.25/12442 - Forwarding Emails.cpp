#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int t_i = 1; t_i <= t; ++t_i) {
    int n;
    cin >> n;
    vector<int> to(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      to[u] = v;
    }

    vector<int> dp(n + 1, 0);
    vector<int> state(n + 1, 0);

    function<int(int)> dfs = [&](int u) -> int {
      state[u] = 1;
      int v = to[u];
      int res = 0;

      if (state[v] == 0) {
        res = dfs(v);
      } else if (state[v] == 1) {
        int cnt = 1;
        for (int x = to[v]; x != v; x = to[x])
          ++cnt;
        int x = v;
        do {
          dp[x] = cnt;
          state[x] = 2;
          x = to[x];
        } while (x != v);
        res = cnt;
      } else {
        res = dp[v];
      }

      if (state[u] != 2) {
        dp[u] = res + 1;
        state[u] = 2;
      }
      return dp[u];
    };

    for (int i = 1; i <= n; ++i)
      if (state[i] == 0)
        dfs(i);

    int best = 1;
    for (int i = 2; i <= n; ++i)
      if (dp[i] > dp[best])
        best = i;

    cout << "Case " << t_i << ": " << best << '\n';
  }
  return 0;
}
