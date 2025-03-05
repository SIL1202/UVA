#include <iostream>
#include <vector>
using namespace std;

int square(vector<vector<char>> &grid, int r, int c) {
  int max_size = 1;
  int m = grid.size();
  int n = grid[0].size();
  char x = grid[r][c];

  for (int h = 1; r - h >= 0 && r + h < m && c - h >= 0 && c + h < n; h++) {
    for (int j = c - h; j <= c + h; j++)
      if (grid[r - h][j] != x || grid[r + h][j] != x)
        return max_size;
    for (int i = r - h; i <= r + h; i++)
      if (grid[i][c - h] != x || grid[i][c + h] != x)
        return max_size;

    max_size = 2 * h + 1;
  }
  return max_size;
}

void solve() {
  int m, n, q;
  cin >> m >> n >> q;
  cout << m << " " << n << " " << q << endl;
  vector<vector<char>> grid(m, vector<char>(n));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }

  int r, c;
  while (q--) {
    cin >> r >> c;
    cout << square(grid, r, c) << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
