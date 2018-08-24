#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e3+5;

int n, k;
int dp[N][N];

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

int mul(int a, int b) {
  return 1ll*a*b%MOD;
}

int main() {
  scanf("%d%d", &n, &k);

  dp[1][0] = 1;
  dp[2][0] = 2;
  for (int i = 3; i <= n; i++) {
    dp[i][0] = mul(dp[i-1][0], 2);
    for (int j = 1; j <= (i-1)/2; j++) {
      int x = mul(dp[i-1][j], add(2, 2*j));
      int y = mul(dp[i-1][j-1], sub(i-2, 2*(j-1)));
      dp[i][j] = add(x, y);
    }
  }

  printf("%d\n", dp[n][k]);
}
