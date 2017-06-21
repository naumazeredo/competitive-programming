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

int n, m, s, t, a, b, ans[N];
set<int> ccadj[N];

// Kosaraju - SCC O(V+E)
vi adj[N], adjt[N];
int ord[N], ordn, scc[N], sccn, vis[N];

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

int ccdfs(int u) {
  if (ans[u] > -1) return ans[u];
  ans[u] = 0;
  for (int v : ccadj[u])
    ans[u] = (ans[u] + ccdfs(v))%MOD;
  return ans[u];
}

int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);

  for (int i = 0; i < m; ++i)
    scanf("%d%d", &a, &b), adj[a].pb(b), adjt[b].pb(a);

  sccn = ordn = 1;
  for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
  for (int i = n; i > 0; --i) if (vis[ord[i]]) dfst(ord[i]), sccn++;

  cl(ans, -1);
  for (int u = 1; u <= n; ++u)
    for (int v : adj[u]) if (scc[u] != scc[v])
      ccadj[scc[u]].insert(scc[v]);
  ans[scc[t]] = 1;

  printf("%d\n", ccdfs(scc[s]));

  return 0;
}
