// Kruskal algorithm
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

vector<int> parent;
int find(int u) { return (parent[u] == u ? u : parent[u] = find(parent[u])); }

bool unite(int u, int v) {
  return (find(u) == find(v) ? false : parent[find(u)] = find(v));
}

struct Edge {
  int u, v;
  double w;
  Edge(int u, int v, double w) : u(u), v(v), w(w) {}
};

void solve() {
  int n, m;
  cin >> m >> n; // channels, outposts

  parent.assign(n, 0);
  iota(parent.begin(), parent.end(), 0);

  vector<pair<int, int>> point(n);
  vector<Edge> edges;
  for (int i = 0; i < n; i++)
    cin >> point[i].first >> point[i].second;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double dx = point[i].first - point[j].first;
      double dy = point[i].second - point[j].second;
      double w = sqrt(dx * dx + dy * dy);
      edges.emplace_back(i, j, w);
    }
  }

  sort(edges.begin(), edges.end(),
       [](const Edge &a, const Edge &b) { return a.w < b.w; });

  int count = 0;
  double answer = 0.0;
  for (const auto &edge : edges) {
    if (count == n - m)
      break;
    if (unite(edge.u, edge.v)) {
      count++;
      answer = edge.w; // maximum edge length
    }
  }

  printf("%.2f\n", answer);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
