#include <stdio.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

void solve() {
  int n, p;
  scanf("%d %d", &n, &p);

  int len[25];
  for (int i = 0; i < p; ++i)
    scanf("%d", &len[i]);

  int dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int i = 0; i < p; ++i) {
    for (int j = n; j >= len[i]; --j) {
      if (dp[j - len[i]])
        dp[j] = 1;
    }
  }

  if (!dp[n])
    printf("NO\n");
  else
    printf("YES\n");
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
