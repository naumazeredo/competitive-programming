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

int n, m, c[N], u, v;
int b[N], t[N];

// Kosaraju - SCC O(V+E)
vi adj[N], adjt[N];
int ord[N], ordn, scc[N], sccn;
int vis[N];

void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) if (!vis[v]) dfs(v);
  ord[ordn++] = u;
}

void dfst(int u) {
  vis[u] = 0;
  for (int v : adjt[u]) if (vis[v]) dfst(v);
  scc[u] = sccn;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) scanf("%d%d", &u, &v), adj[u].pb(v), adjt[v].pb(u);

  sccn = ordn = 0;
  for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
  for (int i = n-1; i >= 0; --i) if (vis[ord[i]]) dfst(ord[i]), sccn++;

  cl(b,63);
  for (int i = 1; i <= n; ++i) {
    if (c[i] == b[scc[i]]) t[scc[i]]++;
    if (c[i] < b[scc[i]]) b[scc[i]] = c[i], t[scc[i]]=1;
  }

  ll sum = 0, ans = 1;
  for (int i = 0; i < sccn; ++i) sum += b[i], ans = (ans * t[i])%MOD;
  printf("%lld %lld\n", sum, ans);

  return 0;
}
