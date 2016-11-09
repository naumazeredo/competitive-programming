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
const int N = 1e5+5;

int n, q, a, b, v[N], rpos[N];
int st[4*N];
int chainno, chain[N], head[N], pos[N], arrsz;
int par[N], sc[N], sz[N];
vi adj[N];

int query_tree(int p, int l, int r, int i, int j) {
  if (r < i or l > j) return INF;
  if (i <= l and j >= r) return st[p];

  int q0 = query_tree(2*p, l, (l+r)/2, i, j);
  int q1 = query_tree(2*p+1, (l+r)/2+1, r, i, j);

  return min(q0, q1);
}

void update_tree(int p, int l, int r, int i) {
  if (r < i or l > i) return;
  if (l == r and l == i) {
    st[p] = (v[l] = !v[l])?l:INF;
    return;
  }

  update_tree(2*p, l, (l+r)/2, i);
  update_tree(2*p+1, (l+r)/2+1, r, i);

  st[p] = min(st[2*p], st[2*p+1]);
}

void dfs(int u) {
  sz[u] = 1;
  sc[u] = 0;
  for (auto v : adj[u]) if (v != par[u]) {
    par[v] = u;
    dfs(v);
    sz[u]+=sz[v];
    if (sz[sc[u]] < sz[v]) sc[u] = v;
  }
}

void hld(int u) {
  if (!head[chainno]) head[chainno] = u;
  chain[u] = chainno;
  pos[u] = ++arrsz;
  rpos[pos[u]] = u;

  if (sc[u]) hld(sc[u]);

  for (auto v : adj[u]) if (v != par[u] and v != sc[u])
    chainno++, hld(v);
}

int query(int v) {
  int ans = INF;
  while (1) {
    if (chain[1] == chain[v]) {
      ans = min(ans, query_tree(1, 1, arrsz, pos[1], pos[v]));
      break;
    }

    ans = min(ans, query_tree(1, 1, arrsz, pos[head[chain[v]]], pos[v]));
    v = par[head[chain[v]]];
  }

  return ans;
}

int main() {
  cl(st, 63);
  cl(v, 0);

  scanf("%d%d", &n, &q);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d%d", &a, &b);
    adj[a].pb(b), adj[b].pb(a);
  }

  dfs(1);

  chainno = arrsz = 0;
  hld(1);

  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &a, &b);
    if (a) {
      int ans = query(b);
      printf("%d\n", ans==INF?-1:rpos[ans]);
    } else {
      update_tree(1, 1, arrsz, pos[b]);
    }
  }

  return 0;
}
