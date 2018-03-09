#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m, h, u[N], a, b, mrk[N];
vector<int> res;

// Kosaraju - SCC O(V+E)
vi adj[N], adjt[N];
int ord[N], ordn, scc[N], sccn, vis[N], sz[N];

void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) if (!vis[v]) dfs(v);
  ord[ordn++] = u;
}

void dfst(int u) {
  vis[u] = 0;
  for (int v : adjt[u]) if (vis[v]) dfst(v);
  scc[u] = sccn;
  sz[scc[u]]++;
}

void dfsres(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  res.push_back(u);

  for (int v : adj[u]) dfs(v);
}

int main() {
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= n; i++) scanf("%d", &u[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);

    if ((u[a]+1)%h == u[b]) {
      adj[a].push_back(b);
      adjt[b].push_back(a);
    }

    if ((u[b]+1)%h == u[a]) {
      adj[b].push_back(a);
      adjt[a].push_back(b);
    }
  }

  // in main
  sccn = ordn = 1;
  for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
  for (int i = n; i > 0; --i) if (vis[ord[i]]) dfst(ord[i]), sccn++;

  for (int u = 1; u <= n; u++) for (int v : adj[u])
    if (scc[u] != scc[v]) mrk[scc[u]] = 1;

  sz[0] = INF;
  int ans = 0;
  for (int i = 1; i < sccn; i++) if (!mrk[i] and sz[ans] > sz[i]) ans = i;

  printf("%d\n", sz[ans]);
  for (int i = 1; i <= n; i++) if (scc[i] == ans) printf("%d ", i);
  printf("\n");

  return 0;
}
