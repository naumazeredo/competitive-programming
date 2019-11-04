#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 5e3+5;

int n, q, k, dp[N][N], ans[N][N];

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return 1ll * a * b % MOD;
}

void precalc() {
  for (int n = 1; n < N; n++) dp[n][1] = 1, ans[n][1] = 1;
  for (int k = 2; k < N; k++) {
    dp[k][k] = 1; ans[k][k] = add(ans[k][k-1], 1);
    for (int n = k+1; n < N; n++) {
      dp[n][k] = add(mul(k, dp[n-1][k]), mul(n-k+1, dp[n-1][k-1]));
      ans[n][k] = add(ans[n][k-1], dp[n][k]);
    }
  }
}

int main() {
  precalc();

  while (~scanf("%d%d", &n, &q)) {
    while (q--) {
      scanf("%d", &k);
      k = min(k, n);

      printf("%d%c", ans[n][k], " \n"[!q]);
    }
  }
}
