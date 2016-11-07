#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e4+5;

int n, a, b, c, dp[21][N], h[N];
vi adj[N], cc[N];
int vis[N];

void dfs(int u) {
  vis[u] = 1;
  for (auto v : adj[u]) if (!vis[v])
    dp[0][v] = u, h[v] = h[u]+1, dfs(v);
}

int lca(int a, int b) {
  if (h[a] > h[b]) swap(a, b);

  for (int i = 20; i >= 0; --i)
    if (h[a] + (1<<i) <= h[b])
      b = dp[i][b];

  if (a == b) return a;

  for (int i = 20; i >= 0; --i)
    if (dp[i][a] != dp[i][b])
      a = dp[i][a], b = dp[i][b];

  return dp[0][a];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &c), cc[c].pb(i);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d%d", &a, &b);
    adj[a].pb(b), adj[b].pb(a);
  }

  dp[0][1] = 1;
  dfs(1);

  for (int i = 1; (1<<i) < n; ++i)
    for (int j = 1; j <= n; ++j)
      dp[i][j] = dp[i-1][dp[i-1][j]];

  ll ans = 0;
  for (int i = 1; i <= n/2; ++i)
    a = cc[i][0], b = cc[i][1],
    ans += h[a] + h[b] - 2 * h[lca(a, b)];

  printf("%lld\n", ans);

  return 0;
}
