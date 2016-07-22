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

vi adj[N], len[N];
int par[N], h[N], sz[N], sc[N], sclen[N];

int chainno, chain[N], head[N], chainpos[N], pos[N], arrsz;
vi chainv[N];

int bit[N];

void add(int p, int v) {
  while (p <= N) bit[p]+=v, p+=p&-p;
}

int query(int p) {
  int sum = 0;
  while (p) sum+=bit[p], p-=p&-p;
  return sum;
}

void dfs(int u) {
  sz[u] = 1;
  sc[u] = 0;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v != par[u]) {
      par[v] = u;
      h[v] = h[u]+1;
      dfs(v);
      if (sz[sc[u]] < sz[v])
        sc[u] = v, sclen[u] = len[u][i];
    }
  }
}

void hld(int u, int c) {
  if (!head[chainno]) head[chainno] = u;
  chain[u] = chainno;
  chainpos[u] = chainv[chainno].size();
  chainv[chainno].pb(u);
  pos[u] = ++arrsz;
  add(pos[u], c);

  if (sc[u]) hld(sc[u], sclen[u]);

  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v != par[u] and v != sc[u])
      chainno++, hld(v, len[u][i]);
  }
}

int lca(int u, int v) {
  while (chain[u] != chain[v]) {
    if (h[head[chain[u]]] < h[head[chain[v]]]) swap(u, v);
    u = par[head[chain[u]]];
  }
  if (h[u] > h[v]) swap(u, v);
  return u;
}

int query_up_sum(int u, int v) {
  int ans = 0;
  while (1) {
    if (chain[u] == chain[v]) {
      if (u == v) break;
      ans += query(pos[u]) - query(pos[v]);
      break;
    }

    ans += query(pos[u]) - query(pos[head[chain[u]]]-1);
    u = par[head[chain[u]]];
  }

  return ans;
}

int query(int u, int v) {
  int l = lca(u, v);
  return query_up_sum(u, l) + query_up_sum(v, l);
}

int query_up_kth(int u, int v, int& k) {
  int ans = 0;
  while (k) {
    if (chain[u] == chain[v]) {
      if (k <= h[u]-h[v]+1) ans = chainv[chain[u]][chainpos[u]-k+1], k = 0;
      else k -= h[u]-h[v]+1;
      break;
    }

    int diff = h[u]-h[head[chain[u]]]+1;
    if (k <= diff) {
      ans = chainv[chain[u]][chainpos[u]-k+1];
      k = 0;
      break;
    }

    ans = head[chain[u]];
    k -= h[u]-h[head[chain[u]]]+1;
    u = par[head[chain[u]]];
  }
  return ans;
}

int query(int u, int v, int k) {
  int l = lca(u, v);
  int ans = query_up_kth(u, l, k);
  if (k == 0) return ans;
  k = h[v]-h[l]+1-k;
  return query_up_kth(v, l, k);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    chainno = 0;
    arrsz = 0;
    cl(bit, 0);
    for (int i = 0; i <= n; ++i) {
      adj[i].clear();
      len[i].clear();
      sc[i] = 0;
      chainv[i].clear();
      head[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      adj[a].pb(b);
      len[a].pb(c);
      adj[b].pb(a);
      len[b].pb(c);
    }

    dfs(1);
    hld(1, 0);

    while (1) {
      scanf("%s", s);
      if (s[1] == 'O') break;
      if (s[1] == 'I') {
        scanf("%d%d", &a, &b);
        printf("%d\n", query(a, b));
      }
      if (s[1] == 'T') {
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", query(a, b, c));
      }
    }
  }
  return 0;
}
