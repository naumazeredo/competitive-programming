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

int d, p, r, b;

int par[300];
int s[300];
int n[300];
int dp[300][20000];

int find(int u) { return par[u]==u ? u : par[u]=find(par[u]); }
void unite(int u, int v) {
  int pu = find(u), pv = find(v);
  par[pu] = pv;
}

int main() {
  while (~scanf("%d%d%d%d", &d, &p, &r, &b)) {
    for (int i = 0; i < d+p; ++i) scanf("%d", &s[i]), par[i] = i, n[i]=0;
    for (int i = 0; i < r; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      unite(x-1, d+y-1);
    }

    for (int i = 0; i < d; ++i)   n[find(i)]--, s[find(i)]+=(i==find(i)?0:s[i]);
    for (int i = d; i < d+p; ++i) n[find(i)]++, s[find(i)]+=(i==find(i)?0:s[i]);

    vector<int> g, gn, gs;
    for (int i = 0; i < d+p; ++i) {
      int f = find(i);
      int ok = 1;
      for (int j = 0; j < g.size(); ++j)
        if (f == g[j])
          ok = 0;
      if (!ok) continue;

      g.pb(f);
      gn.pb(n[f]);
      gs.pb(s[f]);
    }

    dp[0][b] = 0;
    for (int i = 0; i < b; ++i) dp[0][i]=-INF;

    for (int i = 1; i <= g.size(); ++i) {
      for (int j = 0; j <= b; ++j) {
        dp[i][j] = dp[i-1][j];
        if (j+gs[i-1]<=b) dp[i][j] = max(dp[i][j], dp[i-1][j+gs[i-1]]+gn[i-1]);
      }
    }

    int m = 0;
    for (int i = 0; i <= b; ++i) m = max(m, dp[g.size()][i]);

    printf("%d ", d+m);

    dp[0][b] = 0;
    for (int i = 0; i < b; ++i) dp[0][i]=-INF;

    for (int i = 1; i <= g.size(); ++i) {
      for (int j = 0; j <= b; ++j) {
        dp[i][j] = dp[i-1][j];
        if (j+gs[i-1]<=b) dp[i][j] = max(dp[i][j], dp[i-1][j+gs[i-1]]-gn[i-1]);
      }
    }

    m = 0;
    for (int i = 0; i <= b; ++i) m = max(m, dp[g.size()][i]);

    printf("%d\n", p+m);
  }

  return 0;
}
