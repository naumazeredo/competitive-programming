#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int INF = 0x3f3f3f3f;

int n, x[20], y[20];
ld dp[1<<20][20];

ld dist(int i, int j) {
  int dx = x[i]-x[j], dy = y[i]-y[j];
  return sqrt(dx*dx+dy*dy);
}

int main() {
  while (scanf("%d", &n), n) {
    for (int i = 0; i < (1<<n); i++)
      for (int j = 0; j < n; j++)
        dp[i][j] = INF;

    scanf("%d%d", &x[n], &y[n]);
    for (int i = 0; i < n ; i++) {
      scanf("%d%d", &x[i], &y[i]);
      dp[1<<i][i] = dist(i, n);
    }

    for (int a = 1; a < (1<<n); a++) {
      if (!(a&(a-1))) continue;
      for (int i = 0; i < n; i++) if ((1<<i)&a) {
        int b = a-(1<<i);
        for (int j = 0; j < n; j++) if ((1<<j)&b)
          dp[a][i] = min(dp[a][i], dp[b][j] + dist(i, j));
      }
    }

    ld ans = INF;
    for (int i = 0; i < n; i++) ans = min(ans, dp[(1<<n)-1][i] + dp[1<<i][i]);
    printf("%.2Lf\n", ans);
  }
  return 0;
}
