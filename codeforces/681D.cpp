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
const int N = 1e5+5;

int n, m, a, b, p[N], h[N], d[N];
vi adj[N];
int vis[N];

int pathn, path[N], ph[N], onpath[N];
vi pathv[N];
int ok;

void dfs(int u, int pa) {
  vis[u]=1;
  path[u] = pa;
  for (int v : adj[u]) h[v] = h[u]+1, dfs(v, pa);
}

void dfsp(int u) {
  vis[u]=1;
  if (h[d[u]] < ph[p[u]]) ok = 0;
  else if (h[d[u]] < h[p[u]] and h[d[u]] > h[d[p[u]]]) ok = 0;
  else if (!onpath[d[u]]) {
    onpath[d[u]]=1;
    pathv[path[u]].pb(d[u]);
  }
  ph[u] = h[d[u]];

  for (int v : adj[u]) dfsp(v);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    p[b] = a;
    adj[a].pb(b);
  }
  for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);

  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    int u = i;
    while (p[u]) u=p[u];
    dfs(u, pathn++);
  }

  cl(vis,0);
  ok = 1;
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    int u = i;
    while (p[u]) u=p[u];
    dfsp(u);
  }

  if (!ok) return 0*printf("-1\n");

  int ans = 0;
  for (int i = 0; i < pathn; ++i) ans += pathv[i].size();

  printf("%d\n", ans);
  for (int i = 0; i < pathn; ++i) for (int j = pathv[i].size()-1; j >= 0; --j)
    printf("%d\n", pathv[i][j]);

  return 0;
}
