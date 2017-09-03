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
typedef pair<ll, pii> plii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

int n, m, q, a, b, c, tt, p[N], sz[N], h[N], anc[N][30], ma[N][30];
int vis[N], d[N];
vi adj[N], adjw[N];
vector<piii> edges;

int find(int a) { return p[a] == a ? a : p[a] = find(p[a]); }
void unite(int a, int b) {
  if ((a=find(a)) == (b=find(b))) return;
  if (sz[a] < sz[b]) swap(a,b);
  p[b] = a;
  sz[a] += sz[b];
}

int dfs(int u, int m) {
  vis[u] = 1;
  d[u] = m;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i], w = adjw[u][i];
    if (!vis[v]) dfs(v, max(m, w));
  }
}

int main() {
  while (~scanf("%d%d", &n, &m) and (n+m)) {
    printf("Instancia %d\n", ++tt);

    edges.clear();
    cl(ma, 0); cl(anc,0);
    for (int i = 0; i < N; i++)
      adj[i].clear(), adjw[i].clear(), p[i] = i, sz[i] = 1;

    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      edges.pb({c, {a,b}});
    }

    sort(edges.begin(), edges.end());
    for (auto e : edges) {
      a = e.nd.st; b = e.nd.nd;
      if (find(a) != find(b)) {
        unite(a, b);
        adj[a].pb(b); adjw[a].pb(e.st);
        adj[b].pb(a); adjw[b].pb(e.st);
      }
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      scanf("%d%d", &a, &b);
      cl(vis,0);
      for (int j = 1; j <= n; j++) d[j] = -INF;
      dfs(a,-INF);
      printf("%d\n", d[b]==-INF?0:d[b]);

      //printf("%d\n", solv(a, b));
    }
    puts("");
  }
  return 0;
}
