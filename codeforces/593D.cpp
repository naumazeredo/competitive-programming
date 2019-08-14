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
const int N = 2e5+5, SQ = 400;

int n, m, h[N], sub[N], par[N], parid[N];
vector<pair<pair<int, ll>, int>> adj[N];
pii pid[N];

void dfs(int u, ll w) {
  db(u _ w);
  sub[u] = u;
  if (h[u]%SQ) {
    if (w == 1) sub[u] = sub[par[u]];
  }

  int i = 0;
  for (auto x : adj[u]) {
    int v = x.st.st;
    ll w = x.st.nd;
    int id = x.nd;

    if (v != par[u]) {
      h[v] = h[u]+1;
      par[v] = u;
      parid[v] = id;
      pid[id] = { v, i };
      dfs(v, w);
    }

    i++;
  }
}

void update(int u, ll w) {
  sub[u] = u;
  if (h[u]%SQ and w == 1) sub[u] = sub[par[u]];

  int i = 0;
  for (auto x : adj[u]) {
    int v = x.st.st;
    ll w = x.st.nd;

    if (v != par[u]) {
      if (h[v]%SQ) dfs(v, w);
    }

    i++;
  }
}

ll query(int u, int v, ll y) {
  vector<ll> uup, vup;
  while (u != v) {
    if (!u or !v) assert(0);
    if (h[u] > h[v]) {
      u = sub[u];
      if (u == 1) continue;

      int id = parid[u];
      ll w = adj[pid[id].st][pid[id].nd].st.nd;
      if (w != 1) uup.push_back(w);
      u = par[u];
    } else {
      v = sub[v];
      if (v == 1) continue;

      int id = parid[v];
      ll w = adj[pid[id].st][pid[id].nd].st.nd;
      if (w != 1) vup.push_back(w);
      v = par[v];
    }

    if (uup.size() + vup.size() > 80) return 0;
  }

  for (auto x : uup) db(x);
  for (auto x : vup) db(x);

  reverse(vup.begin(), vup.end());
  for (auto x : uup) y /= x;
  for (auto x : vup) y /= x;

  return y;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int u, v, i = 0; i < n-1; i++) {
    ll w;
    scanf("%d%d%lld", &u, &v, &w);
    adj[u].push_back({ { v, w }, i+1 });
    adj[v].push_back({ { u, w }, i+1 });
  }

  dfs(1, 0);
  for (int i = 1; i <= n; i++) db(i _ h[i] _ par[i]);

  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int a, b;
      ll y;

      scanf("%d%d%lld", &a, &b, &y);
      printf("%lld\n", query(a, b, y));
    } else {
      int p;
      ll x;

      scanf("%d%lld", &p, &x);

      auto& r = adj[par[pid[p].st]][pid[p].nd];
      r = { { r.st.st, x }, r.nd };
      update(pid[p].st, x);
    }
  }

  return 0;
}
