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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e4+5;

int n, a, b;

vi adj[2][N];
int vis[N], p[N], sz[N];
vi centr[2];

map<map<int, int>, int> m;

void dfscentr(int t, int u) {
  vis[u] = 1;
  sz[u] = 1;

  int ok = 1;
  for (int v : adj[t][u]) {
    if (v == p[u]) continue;
    if (!vis[v]) p[v]=u, dfscentr(t, v);
    sz[u] += sz[v];
    if (sz[v] > n/2) ok=0;
  }
  if (n-sz[u] > n/2) ok=0;
  if (ok) centr[t].pb(u);
}

int dfs(int t, int u) {
  vis[u]=1;
  map<int, int> c;
  for (int v : adj[t][u]) {
    if (v == p[u]) continue;
    if (!vis[v]) p[v]=u, dfs(t, v);
    c[sz[v]]++;
  }

  if (!m.count(c)) m[c] = m.size();
  return sz[u]=m[c];
}

int main() {
  while (~scanf("%d", &n)) {
    m.clear();
    centr[0].clear(), centr[1].clear();
    for (int i = 0; i <= n; ++i) adj[0][i].clear(), adj[1][i].clear();

    for (int i = 0; i < n-1; ++i) scanf("%d%d", &a, &b), adj[0][a].pb(b), adj[0][b].pb(a);
    for (int i = 0; i < n-1; ++i) scanf("%d%d", &a, &b), adj[1][a].pb(b), adj[1][b].pb(a);

    cl(vis,0);
    p[1] = -1;
    dfscentr(0, 1);

    cl(vis,0);
    p[1] = -1;
    dfscentr(1, 1);

    cl(vis,0);
    p[centr[1][0]] = -1;
    int en = dfs(1, centr[1][0]);

    cl(vis,0);
    p[centr[0][0]] = -1;
    int eq = dfs(0, centr[0][0]) == en;
    if (!eq and centr[0].size()>1) {
      cl(vis,0);
      p[centr[0][1]]=-1;
      eq = dfs(0, centr[0][1]) == en;
    }

    printf("%c\n", eq?'S':'N');
  }

  return 0;
}
