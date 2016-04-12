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

int t, n, m, g, x;
vector<int> gr[300];
int res;

int dp[201][201][301];

void go(int c, int a, int v) {
  if (v > x) return;
  if (c > m) return;
  if (a > g) return;

  if (dp[c][a][v]) return;
  dp[c][a][v] = 1;

  res = max(res, v);

  go(c, a+1, v);
  for (int i = 0; i < gr[a].size(); ++i)
    go(c+1, a+1, v+gr[a][i]);
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    memset(dp, 0, sizeof(dp));

    scanf("%d%d%d%d", &n, &m, &g, &x);
    for (int i = 0; i < g; ++i) gr[i].clear();
    for (int i = 0; i < g; ++i) {
      int q, a;
      scanf("%d", &q);
      for (int j = 0; j < q; ++j) scanf("%d", &a), gr[i].pb(a);
    }

    res = 0;
    go(0, 0, 0);
    printf("Caso #%d: %d\n", tt, res);
  }
  return 0;
}
