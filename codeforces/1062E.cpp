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
const int N = 1e5+5, M = 1e6+5, SQ = 400;

int n, q, p[N], tin[N], tout[N], t, h[N];
vector<int> adj[N];

int st[4*M], H[M];
pii stmi[4*N], stma[4*N];

void dfs(int u) {
  H[t] = h[u];
  tin[u] = t++;
  for (int v : adj[u]) {
    h[v] = h[u]+1;
    dfs(v);

    H[t] = h[u];
    tout[u] = t++;
  }
}

void build(int p = 1, int l = 0, int r = t-1) {
  if (l == r) { st[p] = H[l]; return; }
  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);
  st[p] = min(st[2*p], st[2*p+1]);
}

int query(int i, int j, int p = 1, int l = 0, int r = t-1) {
  if (i > r or j < l) return INF;
  if (i <= l and r <= j) return st[p];
  int m = (l+r)/2;
  return min(query(i, j, 2*p, l, m), query(i, j, 2*p+1, m+1, r));
}

pii mergemi(pii a, pii b) {
  pii res = a;
  if (tin[b.st] <= tin[a.st] and tin[b.nd] <= tin[a.st]) res = b;
  else if (tin[b.st] <= tin[a.st]) res = { b.st, a.st };
  else if (tin[b.st] <= tin[a.nd]) res = { a.st, b.st };
  return res;
}

pii mergema(pii a, pii b) {
  pii res = a;
  if (tin[b.nd] >= tin[a.st]) res = b;
  else if (tin[b.st] >= tin[a.st]) res = { b.st, a.st };
  else if (tin[b.st] >= tin[a.nd]) res = { a.st, b.st };
  return res;
}

void build2(int p = 1, int l = 1, int r = n) {
  if (l == r) {
    stmi[p] = { l, 0 };
    stma[p] = { l, n+1 };
    return;
  }

  int m = (l+r)/2;
  build2(2*p, l, m);
  build2(2*p+1, m+1, r);

  stmi[p] = mergemi(stmi[2*p], stmi[2*p+1]);
  stma[p] = mergema(stma[2*p], stma[2*p+1]);
}

pii querymi(int i, int j, int p = 1, int l = 1, int r = n) {
  if (i > r or j < l) return {0, 0};
  if (i <= l and r <= j) return stmi[p];
  int m = (l+r)/2;
  return mergemi(querymi(i, j, 2*p, l, m), querymi(i, j, 2*p+1, m+1, r));
}

pii queryma(int i, int j, int p = 1, int l = 1, int r = n) {
  if (i > r or j < l) return {n+1, n+1};
  if (i <= l and r <= j) return stma[p];
  int m = (l+r)/2;
  return mergema(queryma(i, j, 2*p, l, m), queryma(i, j, 2*p+1, m+1, r));
}

pii solve(int l, int r) {
  auto mi = querymi(l, r);
  auto ma = queryma(l, r);

  int ql = query(tin[mi.st], tin[ma.nd]);
  int qr = query(tin[mi.nd], tin[ma.st]);
  if (ql >= qr) return { ma.st, ql };
  return { mi.st, qr };
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; i++) scanf("%d", &p[i]), adj[p[i]].push_back(i);
  dfs(1);
  tin[0] = INF; tin[n+1] = -1;
  build();
  build2();

  for (int l, r, i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    auto s = solve(l, r);
    printf("%d %d\n", s.st, s.nd);
  }

  return 0;
}
