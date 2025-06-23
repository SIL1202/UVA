// Shortest path and maximum bottleneck problem
// using Dijkstra's algorithm with priority_queue

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define INF (int)1e8
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

int main() {
  int n, m;
  int t = 0;
  while (cin >> n >> m && n != 0 && m != 0) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      adj[a].emplace_back(b, w);
      adj[b].emplace_back(a, w);
    }
    int S, D, T;
    cin >> S >> D >> T;

    priority_queue<pii> pq; // Max-Heap
    vector<int> capacity(n + 1, 0);
    capacity[S] = INF;
    pq.emplace(INF, S);

    while (!pq.empty()) {
      auto [cap, u] = pq.top();
      pq.pop();

      if (u == D)
        break;
      for (auto [v, w] : adj[u]) {
        int bottleneck = min(cap, w);
        if (bottleneck > capacity[v]) {
          capacity[v] = bottleneck;
          pq.emplace(capacity[v], v);
        }
      }
    }

    int bottleneck = capacity[D] - 1; // -1 for the guide
    int trips = T / bottleneck + (T % bottleneck ? 1 : 0);
    cout << "Scenario #" << ++t << '\n';
    cout << "Minimum Number of Trips = " << trips << '\n';
    cout << '\n';
  }
  return 0;
}
