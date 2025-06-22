// MST using Prim's algorithm
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int t_i = 0; t_i < t; t_i++) {
    int n;
    cin >> n;
    vector<pair<double, double>> node(n);
    for (int i = 0; i < n; ++i)
      cin >> node[i].first >> node[i].second;

    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double dx = node[i].first - node[j].first;
        double dy = node[i].second - node[j].second;
        double dr = sqrt(dx * dx + dy * dy);
        adj[i].emplace_back(j, dr);
        adj[j].emplace_back(i, dr);
      }
    }

    double total = 0.0;
    // {dist, node}
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        pq;
    vector<bool> visited(n, false);
    pq.emplace(0, 0);
    while (!pq.empty()) {
      pair<double, int> top = pq.top();
      pq.pop();
      double d = top.first;
      int u = top.second;
      if (visited[u])
        continue;
      visited[u] = true;
      total += d;
      for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        double w = adj[u][i].second;
        if (!visited[v])
          pq.emplace(w, v);
      }
    }
    if (t_i != 0)
      cout << '\n';
    printf("%.2f\n", total);
  }
  return 0;
}
