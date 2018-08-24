// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const int N = 5e5+5;

struct DSU {
  vector<int> p;
  void init(int n) {
    p.resize(n+1);
    iota(p.begin(), p.end(), 0);
  }
  int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
  int unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return 0;
    p[v] = u; return 1;
  }
} mst, pathcomp;

int n, k, m;
vector<pii> adj[N];
int p[N][20], h[N], isquery[N];
int ans[N];
vector<piii> edges;

void dfs(int u) {
  for (int i = 1; i < 20; i++)
    p[u][i] = p[p[u][i-1]][i-1];

  for (pii x : adj[u]) {
    int v = x.st, w = x.nd;
    if (v != p[u][0]) {
      if (w == 0) isquery[v] = 1;
      h[v] = h[u]+1;
      p[v][0] = u;
      dfs(v);
    }
  }
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = 19; i >= 0; i--)
    if (h[u] - (1<<i) >= h[v])
      u = p[u][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; i--)
    if (p[u][i] != p[v][i])
      u = p[u][i], v = p[v][i];
  return p[u][0];
}

void paint(int a, int l, int w) {
  a = pathcomp.find(a);
  if (h[a] <= h[l]) return;
  ans[a] = w;
  paint(p[a][0], l, w);
  pathcomp.unite(p[a][0], a);
}

int main() {
  scanf("%d%d%d", &n, &k, &m);

  mst.init(n+1);
  pathcomp.init(n+1);

  for (int a, b, i = 0; i < k; i++) {
    scanf("%d%d", &a, &b);
    mst.unite(a, b);
    adj[a].push_back({ b, 0 });
    adj[b].push_back({ a, 0 });
  }

  for (int a, b, w, i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &w);
    if (mst.unite(a, b)) {
      adj[a].push_back({ b, w });
      adj[b].push_back({ a, w });
    } else edges.push_back({ w, { a, b } });
  }

  for (int i = 1; i <= n; i++) if (!p[i][0]) p[i][0] = i, dfs(i);

  for (auto e : edges) {
    int w = e.st;
    int a = e.nd.st;
    int b = e.nd.nd;
    int l = lca(a, b);
    paint(a, l, w);
    paint(b, l, w);
  }

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    if (isquery[i]) {
      if (!ans[i]) return !printf("-1\n");
      sum += ans[i];
    }
  }

  printf("%lld\n", sum);

  return 0;
}
