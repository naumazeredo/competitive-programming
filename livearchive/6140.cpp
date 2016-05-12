#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

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
const int N = 1e5+5;

int n, q, a, b;
int par[N];

int dist[N];

int cyclesize[N];

int cycle[N], cycledist[N], cyclepar[N], cyclemin[N];
int cn;

int dp[N][30];

int cs;
int vis[N];
int dfs(int u) {
  vis[u] = 1;

  if (vis[par[u]] == 1) {
    cs = par[u];

    cycle[u] = ++cn;
    cycledist[u] = 0;
    cyclepar[u] = u;
    cyclemin[u] = dist[u] - dist[par[u]];

    cyclesize[cn] = dist[u]+1-dist[par[u]];

    par[u] = u;
  } else if (vis[par[u]] == 2) {
    cycle[u] = cycle[par[u]];
    cycledist[u] = cycledist[par[u]] + 1;
    cyclepar[u] = cyclepar[par[u]];
  } else {
    dist[par[u]] = dist[u]+1;
    dfs(par[u]);

    cycle[u] = cycle[par[u]];

    if (cs) {
      cycledist[u] = 0;
      cyclepar[u] = u;
      cyclemin[u] = dist[u] - dist[cs];
    } else {
      cycledist[u] = cycledist[par[u]]+1;
      cyclepar[u] = cyclepar[par[u]];
    }

    if (cs == u) cs = 0;
  }

  vis[u] = 2;
}

int query(int a, int b) {
  if (cycledist[b] > cycledist[a]) swap(a, b);
  if (cycledist[a] > cycledist[b]) {
    for (int i = 20; i >= 0; --i)
      if (cycledist[a] - cycledist[b] >= (1<<i))
        a = dp[a][i];
  }

  if (a == b) return a;

  for (int i = 20; i >= 0; --i)
    if (dp[a][i] != dp[b][i])
      a = dp[a][i], b = dp[b][i];;

  return par[a];
}

int main() {
  while (~scanf("%d", &n)) {
    cl(vis);
    for (int i = 1; i <= n; ++i) scanf("%d", &par[i]);

    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);

    for (int i = 1; i <= n; ++i) dp[i][0] = par[i];
    for (int j = 0; j < 20; ++j) for (int i = 1; i <= n; ++i) dp[i][j+1] = dp[dp[i][j]][j];

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      scanf("%d%d", &a, &b);

      if (cycle[a] != cycle[b]) {
        printf("-1\n");
      } else if (cyclepar[a] != cyclepar[b]) {
        int cyclepath = abs(cyclemin[cyclepar[a]] - cyclemin[cyclepar[b]]);
        printf("%d\n", cycledist[a] + cycledist[b] + min(cyclesize[cycle[a]] - cyclepath, cyclepath));
      } else {
        // LCA
        printf("%d\n", cycledist[a] + cycledist[b] - 2 * cycledist[query(a, b)]);
      }
    }
  }
  return 0;
}
