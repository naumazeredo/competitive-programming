// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 4e3+5;

// 2-SAT - O(V+E)
// For each variable x, we create two nodes in the graph: u and !u
// If the variable has index i, the index of u and !u are: 2*i and 2*i+1
int n, m;
/*
int ans[N], cn, vis[N], sccn, scc[N], scch[N], hu[N], hd[N], h[N];
vector<int> stk, adj[N], radj[N];
set<int> nadj[N], rnadj[N];

void koj(int u) {
  vis[u] = 1;
  for (int v : adj[u]) if (!vis[v]) koj(v);
  stk.pb(u);
}

void rkoj(int u) {
  vis[u] = 0;
  for (int v : radj[u]) if (vis[v]) rkoj(v);
  scc[u] = sccn;
}

void rsat(int);

void sat(int u) {
  if (ans[u] != -1) return;
  ans[u] = 1, rsat(u^1);
  for (int v : adj[u]) sat(v);
}

void rsat(int u) {
  if (ans[u] != -1) return;
  ans[u] = 0, sat(u^1);
  for (int v : radj[u]) rsat(v);
}

bool sat() {
  sccn = 1; // Kosaraju's
  for (int i = 2; i <= cn; i++) if (!vis[i]) koj(i);
  while (stk.size()) {
    int u = stk.back(); stk.pop_back();
    if (vis[u]) rkoj(u), scch[sccn++] = u;
  }

  // Checks if exists a valid assingment.
  for (int i = 2; i <= cn; i+=2) if (scc[i] == scc[i^1]) return 0;

  memset(ans, -1, sizeof ans);
  // To set value of x to true (or false) call sat(x) (or sat(x^1)) below.

  // Finds a valid assignment. Erase if not needed.
  for(int i = sccn - 1; i > 0; --i) sat(scch[i]);

  // Check for inconsistencies in implication graph.
  for (int u = 2; u <= cn; u++) if (ans[u] == 1)
    for (int v : adj[u]) if (!ans[v]) return 0;

  return 1;
}

void reset() {
  memset(ans, -1, sizeof ans);
  for(int i=0; i<=cn; ++i) adj[i].clear(), radj[i].clear();
  cn = 0;
}

void build(int u) {
  vis[u] = 1;
  h[scc[u]] |= u&1;
  for (int v : adj[u]) if (!vis[v]) {
    build(v);
    if (scc[v] != scc[u]) nadj[u].insert(v), rnadj[v].insert(u);
  }
}

void dfs_down(int u) {
  vis[u] = 1;
  hd[u] |= h[u];
  for (int v : nadj[u]) if (!vis[v]) dfs_down(v), hd[u] |= hd[v];
}

void dfs_up(int u) {
  vis[u] = 1;
  hu[u] |= h[u];
  for (int v : rnadj[u]) if (!vis[v]) dfs_up(v), hu[u] |= hu[v];
}
*/

int g[N][N], cnt;
int vis[N], d[N], u[N];
vector<int> adj[N];

void add_clause(int x, int y) {
  adj[x^1].pb(y), adj[y^1].pb(x);
}

void build_all(int u, int p) {
  if (vis[u] == cnt) return;
  vis[u] = cnt;
  g[p][u] = 1;

  for (int v : adj[u]) build_all(v, p);
}

void pre() {
  for (int i = 3; i <= 2*n+2; i+=2) d[i] = u[i] = i&1;
  for (int i = 2; i <= 2*n+2; i+=2) for (int j = 2; j <= 2*n+2; j++) if (i != j) {
    if (g[i][j] and d[j]) d[i] = 1;
    if (g[i][j] and u[j]) u[i] = 1;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int a, b, i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    a *= 2;
    if (a < 0) a = -a+1;
    b *= 2;
    if (b < 0) b = -b+1;
    add_clause(a, b);
  }

  /*
  sat();
  memset(vis, 0, sizeof vis);
  for (int i = 2; i <= cn; i++) if (!vis[i]) build(i);
  memset(vis, 0, sizeof vis);
  for (int i = 2; i <= cn; i++) if (!vis[i]) dfs_down(i);
  memset(vis, 0, sizeof vis);
  for (int i = 2; i <= cn; i++) if (!vis[i]) dfs_up(i);

  for (int i = 1; i <= n; i++) {
    int a = 2*i, b = 2*i+1;
    if (scc[a] > scc[b]) swap(a, b);
    if (hd[scc[a]] and hu[
  }
  */

  for (int i = 2; i <= 2*n+2; i++) cnt++,  build_all(i, i);
  for (int i = 1; i <= n; i++) if (g[2*i][2*i+1] and g[2*i+1][2*i]) return !printf("0\n");
  pre();

  int ans = 3;
  for (int i = 1; i <= n; i++) {
    int a = 2*i, b = 2*i+1;
    //db(i _ a _ b _ g[a][b] _ g[b][a]);
    if (g[a][b] and u[a]) ans = 1;
    if (g[b][a] and d[a]) ans = 1;
    if (!g[a][b] and !g[b][a] and d[a]) ans = min(ans, 2);
  }

  printf("%d\n", ans > 2 ? -1 : ans);

  return 0;
}
