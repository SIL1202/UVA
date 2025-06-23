// Shortest path using Dijkstra's algorithm
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 5e8;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

int main() {
  int t;
  cin >> t;
  for (int t_i = 1; t_i <= t; t_i++) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vvpii adj(n);
    for (int i = 0; i < m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      adj[a].emplace_back(b, w);
      adj[b].emplace_back(a, w);
    }

    priority_queue<pii, vpii, greater<pii>> pq;
    vector<int> dist(n, INF);
    dist[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[u])
        continue;

      for (auto [v, w] : adj[u]) {
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pq.emplace(dist[v], v);
        }
      }
    }

    cout << "Case #" << t_i << ": ";
    if (dist[t] == INF)
      cout << "unreachable\n";
    else
      cout << dist[t] << '\n';
  }
  return 0;
}
