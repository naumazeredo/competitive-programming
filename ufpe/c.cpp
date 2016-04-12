#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int t, n, m;
char g[2222][2222];
int dp[2222][2222];
vi x[2222], y[2222];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 2222; ++i) x[i].clear(), y[i].clear();

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
      scanf(" %c", &g[i][j]), g[i][j] = g[i][j]=='C';
      if (g[i][j]) dp[i][j] = dp[i][j-1]+1, x[dp[i][j]].pb(j), y[dp[i][j]].pb(i);
    }

    memset(dp, 0, sizeof(dp));

    int res = 0;
    for (int i = m; i >= 0; --i) {
      int mx = 0;
      for (int j = 0; j < x[i].size(); ++j) {
        int ux = x[i][j], uy = y[i][j];
        int v = 1 + dp[uy-1][ux] + dp[uy+1][ux];
        dp[uy][ux] = dp[uy-dp[uy-1][ux]][ux] = dp[uy+dp[uy+1][ux]][ux] = v;
        mx = max(mx, dp[uy][ux]);
      }
      res += mx;
    }

    printf("Caso #%d: %d\n", tt, res);
  }
  return 0;
}
