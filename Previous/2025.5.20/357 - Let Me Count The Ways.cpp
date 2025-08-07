#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MAX = 30000;
  vector<long long> dp(MAX + 1, 0);
  dp[0] = 1;

  int coins[] = {1, 5, 10, 25, 50};
  for (int c : coins)
    for (int i = c; i <= MAX; ++i)
      dp[i] += dp[i - c];

  int n;
  while (cin >> n) {
    if (dp[n] == 1)
      cout << "There is only 1 way to produce " << n << " cents change.\n";
    else
      cout << "There are " << dp[n] << " ways to produce " << n
           << " cents change.\n";
  }
  return 0;
}
