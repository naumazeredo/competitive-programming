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
const int N = 1e5+5;

int t, n, q;
vector<pii> adj[N];
int p[20][N], vis[N], h[N];
ll d[20][N];
int extra_u, extra_v, extra_w;

void dfs(int u) {
  vis[u] = 1;

  for (int i = 1; i < 20; i++) {
    p[i][u] = p[i-1][p[i-1][u]];
    d[i][u] = d[i-1][u] + d[i-1][p[i-1][u]];
  }

  /*
  for (int i = 0; i < 20; i++)
    if (i <= 3)
      db(i _ u _ p[i][u] _ d[i][u]);
  dbs("");
  */

  for (pii x : adj[u]) {
    int v = x.st;
    int w = x.nd;
    if (vis[v]) {
      if (v != p[0][u]) extra_u = u, extra_v = v, extra_w = w;
      continue;
    }

    p[0][v] = u;
    d[0][v] = w;
    h[v] = h[u]+1;
    dfs(v);
  }
}

ll lca(int u, int v) {
  ll res = 0;

  if (h[u] < h[v]) swap(u, v);
  for (int i = 19; i >= 0; i--)
    if (h[u] - (1<<i) >= h[v])
      res += d[i][u], u = p[i][u];

  if (u == v) return res;

  for (int i = 19; i >= 0; i--)
    if (p[i][u] != p[i][v])
      res += d[i][u], u = p[i][u],
      res += d[i][v], v = p[i][v];

  res += d[0][u] + d[0][v];
  return res;
}

ll solv(int u, int v) {
  //db(u _ v _ extra_u _ extra_v);
  ll res = lca(u, v);
  res = min(res, lca(u, extra_u) + extra_w + lca(v, extra_v));
  //db(lca(u, extra_u) + extra_w + lca(v, extra_v));
  res = min(res, lca(u, extra_v) + extra_w + lca(v, extra_u));
  //db(lca(u, extra_v) + extra_w + lca(v, extra_u));
  return res;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = 0;

    for (int u, v, w, i = 0; i < n; i++) {
      scanf("%d%d%d", &u, &v, &w);
      adj[u].push_back({ v, w });
      adj[v].push_back({ u, w });
    }

    p[0][1] = 1;
    dfs(1);
    /*
    db(extra_u _ extra_v _ extra_w);
    db(lca(3, 4) _ lca(4, 3));
    */

    for (int u, v, i = 0; i < q; i++) {
      scanf("%d%d", &u, &v);
      printf("%lld\n", solv(u, v));
    }
  }
  return 0;
}
