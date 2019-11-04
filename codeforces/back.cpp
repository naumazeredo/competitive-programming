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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5+5;

int n, m;
vector<pair<pair<int, ll>, int>> adj[N];
map<int, int> mi;

int h[N], sz[N], in[N], out[N], t, rin[N], nxt[N];
ll st[4*N];

void update(int x, ll v, int p = 1, int l = 0, int r = N-1) {
  if (x < l or x > r) return;
  if (x == l and l == r) { st[x] = v; return; }

  int m = (l+r)/2;
  update(x, v, 2*p, l, m);
  update(x, v, 2*p+1, m+1, r);
  if (LINF/st[2*p]/st[2*p+1]) st[p] = LINF;
  else st[p] = st[2*p] * st[2*p+1];
}

void dfs_sz(int u) {
  sz[u] = 1;
  for (auto& x : adj[u]) {
    int v = x.st.st;
    h[v] = h[u]+1;
    dfs_sz(v);
    sz[u] += sz[v];
    if (sz[v] > sz[adj[u][0].st.st])
        swap(x, adj[u][0]);
  }
}

void dfs_hld(int u) {
  in[u] = t++;
  rin[in[u]] = u;
  for (auto x : adj[u]) {
    int v = x.st.st;
    ll w = x.st.nd;
    int id = x.nd;

    mi[id] = in[v];

    nxt[v] = (v == adj[u][0].st.st ? nxt[u] : v);
    update(in[v], w);
    dfs_hld(v);
  }
  out[u] = t;
}

int lca(int a, int b) {
  while (nxt[a] != nxt[b]) {
    if (h[nxt[a]] > h[nxt[b]]) swap(a, b);
    a = nxt[a];
  }
  return h[a] < h[b] ? a : b;
}

ll query(int a, int b) {
  return query
}

int main() {
  scanf("%d%d", &n, &m);
  for (int u, v, i = 0; i < n-1; i++) {
    ll w;
    scanf("%d%d%lld", &u, &v, &w);
    adj[u].push_back({ { v, w }, i+1 });
    adj[v].push_back({ { u, w }, i+1 });
  }

  dfs_sz(1);
  dfs_hld(1);

  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int a, b;
      ll y;

      scanf("%d%d%lld", &a, &b, &y);
    } else {
      int p;
      ll x;

      scanf("%d%lld", &p, &x);
      update(mi[p], x);
    }
  }

  return 0;
}
