#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int dp[505][505];

int h, w;
char g[505][505];
int q;
int r1, r2, c1, c2;

int main() {
  scanf("%d%d", &h, &w);
  for (int i = 1; i <= h; ++i) for (int j = 1; j <= w; ++j) scanf(" %c", &g[i][j]);

  for (int i = 2; i <= w; ++i) dp[1][i] = dp[1][i-1] + (g[1][i] == '.' && g[1][i-1] == '.');
  for (int i = 2; i <= w; ++i) dp[i][1] = dp[i-1][1] + (g[i][1] == '.' && g[i-1][1] == '.');
  for (int i = 2; i <= h; ++i) for (int j = 2; j <= w; ++j)
    dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (g[i][j] == '.' && g[i][j-1] == '.')+ (g[i][j] == '.' && g[i-1][j] == '.');

  /*
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j)
      printf("%d ", dp[i][j]);
    printf("\n");
  }
  */

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int c = dp[r2][c2] - dp[r2][c1] - dp[r1][c2] + dp[r1][c1];
    for (int i = r1+1; i <= r2; ++i) c += (g[i][c1] == '.' && g[i-1][c1] == '.');
    for (int i = c1+1; i <= c2; ++i) c += (g[r1][i] == '.' && g[r1][i-1] == '.');
    printf("%d\n", c);
  }

  return 0;
}
