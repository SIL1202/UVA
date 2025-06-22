// MST using Prim's algorithm
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m && n != 0 && m != 0) {
    vector<vector<pair<int, int>>> adj(n);
    int original = 0;
    for (int i = 0; i < m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      original += w;
      adj[a].emplace_back(b, w);
      adj[b].emplace_back(a, w);
    }

    // clang-format off
    // { dist, node }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int total = 0;
    vector<bool> visited(n, false);
    pq.emplace(0, 0);

    while(!pq.empty()){
      auto [d, u] = pq.top(); pq.pop();
      if(visited[u]) continue;
      visited[u] = true;
      total += d;
      for(auto &[v, w]: adj[u])
        if(!visited[v])
          pq.emplace(w, v);
    }
    cout << original - total << '\n';
    // clang-format on
  }
  return 0;
}
