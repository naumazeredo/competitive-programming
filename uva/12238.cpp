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
const int N = 1e5+5;

int n, q, a, b, h[N], l[N], dp[25][N];
ll d[N];
vi adj[N];

void dfs(int u) {
  for (int v : adj[u])
    h[v] = h[u]+1, d[v] = d[u]+l[v], dfs(v);
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
  while (~scanf("%d", &n) and n) {
    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &dp[0][i], &l[i]);
      adj[dp[0][i]].pb(i);
    }

    dfs(0);

    for (int i = 1; (1<<i) < n; ++i)
      for (int j = 0; j < n; ++j)
        dp[i][j] = dp[i-1][dp[i-1][j]];

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      scanf("%d%d", &a, &b);
      printf("%lld%c", d[a] + d[b] - 2*d[lca(a, b)], i<q-1?' ':'\n');
    }
  }
  return 0;
}
