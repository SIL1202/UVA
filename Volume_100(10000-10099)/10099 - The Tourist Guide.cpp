// clang-format off

// Shortest path and maximum bottleneck problem
//
// method 1 -> Using modified Dijkstra's algorithm:
//             Instead of minimizing distance, we maximize the minimum capacity
//             (bottleneck) along the path using a max-heap.
//
// method 2 -> Using modified Floyd-Warshall algorithm:
//             Instead of computing shortest sums, we compute the maximum
//             bottleneck between all pairs using: cap[i][j] = max(cap[i][j], min(cap[i][k], cap[k][j])).
//
// method 3 -> Using Kruskal's algorithm with Union-Find:
//             Sort all edges by capacity descendingly, add edges one by one,
//             and stop once the source and destination are connected.
//             The last edge added defines the bottleneck.

// 方法一：改寫 Dijkstra 演算法，從最短路改為最大瓶頸，使用最大堆維護目前路徑可承受的最大最小邊。
// 方法二：改寫 Floyd-Warshall，從最短距離改為最大瓶頸，更新規則為 cap[i][j] = max(cap[i][j], min(cap[i][k], cap[k][j])). 
// 方法三：使用 Kruskal + Union-Find，將邊由大排到小，逐一加入直到起點與終點相連，最後加入的邊即為瓶頸。

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
#include <tuple>
using namespace std;

#define INF (int)1e8
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
enum Mode { DIJKSTRA = 0, FLOYD = 1, KRUSKAL = 2 };
Mode mode = DIJKSTRA;

// clang-format off
int solve_dijkstra(int n, int s, int d, int t, const vector<vector<pii>> &adj);
int solve_floyd(int n, int s, int d, int t, const vector<tuple<int,int,int>> &edges);
int solve_kruskal(int n, int s, int d, int t, const vector<tuple<int,int,int>> &edges);

int main() {
  int n, m;
  int T = 0;
  while (cin >> n >> m && n != 0 && m != 0) {
    vector<tuple<int, int, int>> edges;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      adj[a].emplace_back(b, w);
      adj[b].emplace_back(a, w);
      edges.emplace_back(w, a, b);
    }
    int s, d, t;
    cin >> s >> d >> t;

    int trips = 0;
    if (mode == DIJKSTRA)
      trips = solve_dijkstra(n, s, d, t, adj);
    else if (mode == FLOYD)
      trips = solve_floyd(n, s, d, t, edges);
    else if (mode == KRUSKAL)
      trips = solve_kruskal(n, s, d, t, edges);

    cout << "Scenario #" << ++T << '\n';
    cout << "Minimum Number of Trips = " << trips << '\n';
    cout << '\n';
  }
  return 0;
}
 
/* ================================================== Dijkstra's algorithm ================================================== */
int solve_dijkstra(int n, int s, int d, int t, const vector<vector<pii>> &adj) {
  vector<int> cap(n + 1, 0);
  cap[s] = INF;
  priority_queue<pii> pq;
  pq.emplace(INF, s);

  while (!pq.empty()) {
    auto [c, u] = pq.top();
    pq.pop();
    if (u == d)
      break;
    for (auto [v, w] : adj[u]) {
      int bottleneck = min(c, w);
      if (bottleneck > cap[v]) {
        cap[v] = bottleneck;
        pq.emplace(bottleneck, v);
      }
    }
  }
  int b = cap[d] - 1;
  return t / b + (t % b ? 1 : 0);
}


/* ================================================== Floyd-Warshall's algorithm ================================================== */
int solve_floyd(int n, int s, int d, int t, const vector<tuple<int, int, int>> &edges) {
  vector<vector<int>> cap(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i)
    cap[i][i] = INF;
  for (auto [u, v, w] : edges)
    cap[u][v] = cap[v][u] = max(cap[u][v], w);

  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cap[i][j] = max(cap[i][j], min(cap[i][k], cap[k][j]));

  int b = cap[s][d] - 1;
  return t / b + (t % b ? 1 : 0);
}

/* ================================================== Kruskal's algorithm ================================================== */
struct DSU {
  vector<int> p;
  DSU(int n) : p(n + 1) { iota(p.begin(), p.end(), 0); }
  int find(int u) { return (p[u] == u ? u : p[u] = find(p[u])); }
  bool unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv)
      return false;
    p[pu] = pv;
    return true;
  }
};

int solve_kruskal(int n, int s, int d, int t,
                  const vector<tuple<int, int, int>> &edges) {
  DSU dsu(n);

  vector<tuple<int, int, int>> sorted_edges = edges;
  sort(sorted_edges.rbegin(), sorted_edges.rend());
  for (auto [w, u, v] : sorted_edges) {
    dsu.unite(u, v);
    if (dsu.find(s) == dsu.find(d)) { // union 直到頭跟尾都連在一起
      int b = w - 1;
      return t / b + (t % b ? 1 : 0);
    }
  }
  return -1;
}
