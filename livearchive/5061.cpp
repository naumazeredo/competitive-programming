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
const int N = 5e4+5;

int t, n, q, a, b, c;
vi adj[N];
int par[N], h[N], sc[N], sz[N];
int chainNo, head[N], chain[N], arrsz, pos[N];
int st[6*N], lz[6*N];

void push(int p) {
  if (lz[p]) {
    st[p] += lz[p];
    lz[2*p] += lz[p];
    lz[2*p+1] += lz[p];
    lz[p] = 0;
  }
}

void update(int p, int l, int r, int i, int j, int v) {
  if (i > r or j < l) return;
  push(p);
  if (i <= l and j >= r) { lz[p] += v; return; }
  update(2*p, l, (l+r)/2, i, j, v);
  update(2*p+1, (l+r)/2+1, r, i, j, v);
}

int query(int p, int l, int r, int i) {
  if (i < l or i > r) return -1;
  push(p);
  if (l == r and l == i) return st[p];
  return max(query(2*p, l, (l+r)/2, i),
             query(2*p+1, (l+r)/2+1, r, i));
}

void dfs(int u) {
  sz[u] = 1;
  for (int v : adj[u]) if (v != par[u]) {
    par[v] = u, h[v] = h[u]+1;
    dfs(v);
    sz[u]+=sz[v];
    if (sc[u] == -1 or sz[v] > sz[sc[u]]) sc[u] = v;
  }
}

void hld(int u) {
  if (head[chainNo] == -1) head[chainNo] = u;
  chain[u] = chainNo;
  pos[u] = arrsz;
  arrsz++;

  if (sc[u] != -1) hld(sc[u]);
  for (int v : adj[u]) if (v != par[u] and v != sc[u])
    chainNo++, hld(v);
}

int lca(int u, int v) {
  while (chain[u] != chain[v]) {
    if (h[head[chain[u]]] < h[head[chain[v]]]) swap(u,v);
    u = par[head[chain[u]]];
  }
  if (h[u] > h[v]) swap(u,v);
  return u;
}

void update_up(int u, int v, int x) {
  while (chain[u] != chain[v]) {
    update(1, 0, arrsz-1, pos[head[chain[u]]], pos[u], x);
    u = par[head[chain[u]]];
  }
  update(1, 0, arrsz-1, pos[v], pos[u], x);
}

void update(int u, int v, int x) {
  int l = lca(u, v);
  update_up(u, l, x);
  update_up(v, l, x);
  update(1, 0, arrsz-1, pos[l], pos[l], -x);
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) adj[i].clear();
    chainNo = 0;
    arrsz = 0;;
    cl(head, -1);
    cl(sc, -1);
    cl(lz, 0);
    cl(st, 0);

    for (int i = 0; i < n-1; ++i) {
      scanf("%d%d", &a, &b);
      adj[a].pb(b);
      adj[b].pb(a);
    }

    dfs(0);
    hld(0);

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      update(a, b, c);
    }

    printf("Case #%d:\n", tt);
    for (int i = 0; i < n; ++i) printf("%d\n", query(1, 0, arrsz-1, pos[i]));
  }
  return 0;
}
