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
const int N = 1e4+5;

int t, n, a, b, c;
char s[40];

vi adj[N], cost[N], edge[N];
int par[N][20], sz[N], h[N];

int chainNo, chainInd[N], chainHead[N], vPos[N], vArray[N], vSize, ev[N];
int st[4*N];

void build(int p, int l, int r) {
  if (l == r) { st[p] = vArray[l]; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = max(st[2*p], st[2*p+1]);
}

int query(int p, int l, int r, int i, int j) {
  if (i > r or j < l) return -INF;
  if (i <= l and j >= r) return st[p];

  int ql = query(2*p, l, (l+r)/2, i, j);
  int qr = query(2*p+1, (l+r)/2+1, r, i, j);

  return max(ql, qr);
}

void update(int p, int l, int r, int x, int c) {
  if (x < l or x > r) return;
  if (l == r and l == x) { st[p] = c; return; }
  update(2*p, l, (l+r)/2, x, c);
  update(2*p+1, (l+r)/2+1, r, x, c);
  st[p] = max(st[2*p], st[2*p+1]);
}

void update(int e, int c) {
  update(1, 0, vSize-1, vPos[ev[e]], c);
}

void hld(int u, int c) {
  if (!chainHead[chainNo]) chainHead[chainNo] = u;
  chainInd[u] = chainNo;
  vPos[u] = vSize;
  vArray[vSize++] = c;

  int ind = -1, ma = -1;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v != par[u][0] and sz[v] > ma)
      ma = sz[v], ind = i;
  }

  if (ind >= 0) hld(adj[u][ind], cost[u][ind]);

  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v != par[u][0] and i != ind) {
      chainNo++;
      hld(v, cost[u][i]);
    }
  }
}

void dfs(int u) {
  sz[u] = 1;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v != par[u][0]) {
      h[v] = h[u]+1;
      par[v][0] = u;
      ev[edge[u][i]] = v;
      dfs(v);
      sz[u]+=sz[v];
    }
  }
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);

  int diff = h[u]-h[v];
  for (int i = 0; i < 20; ++i) if ((diff>>i)&1) u = par[u][i];

  /*
  for (int i = 19; i >= 0; --i) if (h[v]+(1<<i)<=h[u])
    u = par[u][i];
  */

  if (u == v) return u;
  for (int i = 19; i >= 0; --i) if (par[u][i] != par[v][i])
    u = par[u][i], v = par[v][i];

  return par[u][0];
}

int query_up(int u, int v) {
  if (u == v) return 0;
  if (chainInd[u] == chainInd[v]) return query(1, 0, vSize-1, vPos[v]+1, vPos[u]);

  int h = chainHead[chainInd[u]];
  int ans = max(ans, query(1, 0, vSize-1, vPos[h], vPos[u]));
  return max(ans, query_up(par[h][0], v));
}

/*
int query_up(int u, int v) {
  if (u == v) return 0;

  int uchain, vchain = chainInd[v], ans = -1;
  while (1) {
    uchain = chainInd[u];
    if (uchain == vchain) {
      if (u == v) break;
      ans = max(ans, query(1, 0, vSize-1, vPos[v]+1, vPos[u]));
      break;
    }

    ans = max(ans, query(1, 0, vSize-1, vPos[chainHead[uchain]], vPos[u]));
    u = par[chainHead[uchain]][0];
  }

  return ans;
}
*/

int query(int u, int v) {
  int l = lca(u, v);
  return max(query_up(u, l), query_up(v, l));
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    chainNo = 0;
    vSize = 0;
    h[1] = 0;
    for (int i = 0; i <= n; ++i) {
      adj[i].clear();
      cost[i].clear();
      edge[i].clear();
      chainHead[i] = 0;
    }

    for (int i = 1; i <= n-1; ++i) {
      scanf("%d%d%d", &a, &b, &c);

      adj[a].pb(b);
      cost[a].pb(c);
      edge[a].pb(i);

      adj[b].pb(a);
      cost[b].pb(c);
      edge[b].pb(i);
    }

    dfs(1);
    hld(1, 0);
    build(1, 0, vSize-1);

    par[1][0] = 1;
    for (int i = 1; (1<<i) <= n; ++i) for (int j = 1; j <= n; ++j)
      par[j][i] = par[par[j][i-1]][i-1];

    while (1) {
      scanf("%s", s);
      if (s[0] == 'D') break;

      scanf("%d%d", &a, &b);
      if (s[0] == 'Q') printf("%d\n", query(a, b));
      if (s[0] == 'C') update(a, b);
    }
  }

  return 0;
}
