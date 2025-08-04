#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    // create grid
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &r : grid)
      for (int &c : r)
        cin >> c;

    int row_corrupt, col_corrupt, bad_row, bad_col;
    row_corrupt = col_corrupt = bad_row = bad_col = 0;

    // check row parity
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j)
        sum += grid[i][j];
      if (sum % 2 != 0) {
        ++row_corrupt;
        bad_row = i + 1;
      }
    }

    // check column parity
    for (int j = 0; j < n; ++j) {
      int sum = 0;
      for (int i = 0; i < n; ++i)
        sum += grid[i][j];
      if (sum % 2 != 0) {
        ++col_corrupt;
        bad_col = j + 1;
      }
    }

    if (row_corrupt == 0 && col_corrupt == 0)
      cout << "OK\n";
    else if (row_corrupt == 1 && col_corrupt == 1)
      cout << "Change bit (" << bad_row << "," << bad_col << ")\n";
    else
      cout << "Corrupt\n";
  }
  return 0;
}
