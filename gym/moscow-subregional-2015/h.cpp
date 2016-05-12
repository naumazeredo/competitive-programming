#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int dp[100005][1005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%x", &a[i]);

  dp[0][0] = a[0];

  int ma = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j <= min(i+1, 1000); ++j) {
    dp[i][j] = max(dp[i-1][j] + (a[i]^(i-j)), dp[i-1][j-1]);
    ma = max(ma, dp[i][j]);
  }

  printf("%d\n", ma);

  return 0;
}
