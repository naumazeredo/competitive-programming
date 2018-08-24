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
const int N = 3e5+5;

int n, m, k, d[N];
pii edges[N];
set<int> adj[N];
vector<pii> ans;

int cn, cc[N], pa[N][20], h[N], vis[N];
vector<int> s;

int lz[N];

int dfs(int u) {
  cc[u] = cn;
  vis[u] = cn;
  int r = 0;
  if (d[u]&1) {
    r = 1;
    s.push_back(u);
  }

  for (int i = 1; i < 20; i++)
    pa[u][i] = pa[pa[u][i-1]][i-1];

  for (int v : adj[u]) if (vis[v] != cn) {
    pa[v][0] = u;
    h[v] = h[u]+1;
    r += dfs(v);
  }
  return r&1;
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = 19; i >= 0; i--)
    if (h[u] - (1<<i) >= h[v])
      u = pa[u][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; i--)
    if (pa[u][i] != pa[v][i])
      u = pa[u][i], v = pa[v][i];
  return pa[u][0];
}

int get(int u) {
  vis[u] = 0;
  for (int v : adj[u]) if (vis[v])
    lz[u] += get(v);

  lz[u] &= 1;
  if (lz[u]) ans.push_back({ u, pa[u][0] });
  return lz[u];
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int a, b, i = 0; i < m; i++)
    scanf("%d%d", &a, &b), d[a] ^= 1, d[b] ^= 1;

  for (int a, b, i = 1; i <= k; i++) {
    scanf("%d%d", &a, &b);
    edges[i] = { a, b };
    adj[a].insert(b);
    adj[b].insert(a);
  }

  for (int i = 1; i <= n; i++) if (d[i]&1 and !cc[i]) {
    cn++;
    pa[i][0] = i;

    s.clear();
    if (dfs(i) or s.size()&1) return !printf("NO\n");

    while (s.size()) {
      int u = s.back(); s.pop_back();
      int v = s.back(); s.pop_back();
      int l = lca(u, v);

      lz[u]++;
      lz[v]++;
      lz[l]--;
      lz[l]--;
    }

    get(i);
  }

  printf("YES\n%d\n", (int)ans.size());
  for (auto x : ans) printf("%d %d\n", x.st, x.nd);

  return 0;
}
