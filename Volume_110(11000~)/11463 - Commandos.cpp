/*
  Online Judge Problem p11463: Commandos
  ------------------------
  題目簡介：
  - 有 N 棟建築，M 條無向道路，每條道路花費時間為 1 單位。
  - Commando 從指定起點 s 出發，放置炸彈於所有建築後，需回到指定集合地點 d。
  - 無限多人同時行動，問：任務完成所需的最少時間。

  解法說明：
  - 觀察：要確保所有建築至少有一個人放置炸彈，最後全部集合。
  - 無限多人意味著：任務時間由 "最慢完成放置 + 集合" 的那個人決定。
  - 轉換為圖問題：
    1. BFS 求起點 s 到所有點的最短距離 dist_from_s。
    2. BFS 求集合點 d 到所有點的最短距離 dist_from_d。
    3. 對每個建築 i：計算 dist_from_s[i] + dist_from_d[i]，取最大值即為答案。

  時間複雜度：O(N + M) per test case
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 單源最短路徑 BFS
vector<int> bfs(int s, vector<vector<int>> &adj, int n) {
  vector<int> dist(n, -1);
  queue<int> q;
  q.push(s);
  dist[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
      if (dist[u] == -1) {
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
  return dist;
}

int main() {
  int t;
  cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int j = 0; j < m; ++j) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    int s, d;
    cin >> s >> d;
    vector<int> dfroms = bfs(s, adj, n);
    vector<int> dfromd = bfs(d, adj, n);

    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (dfroms[i] != -1 && dfromd[i] != -1)
        ans = max(ans, dfroms[i] + dfromd[i]);

    cout << "Case " << case_num << ": " << ans << '\n';
  }
  return 0;
}
