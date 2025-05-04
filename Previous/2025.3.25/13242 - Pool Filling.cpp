#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int cap, tar;
  cin >> cap >> tar;
  int n;
  cin >> n;

  vector<pair<int, int>> jar(n);
  for (int i = 0; i < n; i++) {
    cin >> jar[i].first >> jar[i].second;
  }

  vector<long long> prefix_volume(n + 1, 0);
  vector<long long> prefix_temp_sum(n + 1, 0);

  for (int i = 0; i < n; i++) {
    prefix_volume[i + 1] = prefix_volume[i] + jar[i].first;
    prefix_temp_sum[i + 1] =
        prefix_temp_sum[i] + 1LL * jar[i].first * jar[i].second;
  }

  int best_l = -1, best_r = -1;
  double best_diff = 1e9;
  bool found = false;

  for (int l = 0; l < n; l++) {
    for (int r = l; r < n && prefix_volume[r + 1] - prefix_volume[l] <= cap;
         r++) {
      long long volume = prefix_volume[r + 1] - prefix_volume[l];
      if (volume < cap / 2.0)
        continue;

      long long numerator = prefix_temp_sum[r + 1] - prefix_temp_sum[l];
      double avg_temp = 1.0 * numerator / volume;

      if (abs(avg_temp - tar) <= 5.0) {
        if ((abs(avg_temp - tar) < best_diff) ||
            (abs(avg_temp - tar) == best_diff &&
             (l < best_l || (l == best_l && r < best_r)))) {
          found = true;
          best_diff = abs(avg_temp - tar);
          best_l = l;
          best_r = r;
        }
      }
    }
  }

  if (!found)
    cout << "Not possible\n";
  else
    cout << best_l << " " << best_r << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
