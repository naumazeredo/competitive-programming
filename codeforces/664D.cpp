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

int n, m, u, v;
char c;
vi adj[N], adjc[N];
int col[N][2];
int vis[N];
int sz, szc;
int ok;

int ans[2];
vi vans[2];
vi tmp[2];

int dfs(int u, int inv) {
  vis[u] = 1;
  for (int i = 0; i < adj[u].size() and ok; ++i) {
    int v = adj[u][i], c = adjc[u][i];
    if (vis[v]) {
      if ((c == inv and col[u][inv] == col[v][inv]) or
          (c != inv and col[u][inv] != col[v][inv]))
        ok = 0;
    } else {
      if (c == inv) col[v][inv] = 1-col[u][inv];
      else col[v][inv] = col[u][inv];
      sz++;
      szc+=col[v][inv];
      dfs(v, inv);
    }
  }
  tmp[col[u][inv]].pb(u);
  int color = col[u][inv];
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d %c", &u, &v, &c);
    c = c=='R';
    adj[u].pb(v), adjc[u].pb(c);
    adj[v].pb(u), adjc[v].pb(c);
  }

  ok = 1;
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    tmp[0].clear();
    tmp[1].clear();
    szc = 0; sz = 1;
    dfs(i, 0);
    if (!ok) { ans[0] = INF; break; }

    ans[0] += min(szc, sz-szc);

    if (szc < sz-szc) for (int v : tmp[1]) vans[0].pb(v);
    else for (int v : tmp[0]) vans[0].pb(v);
  }

  ok = 1;
  cl(vis,0);
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    tmp[0].clear();
    tmp[1].clear();
    szc = 0; sz = 1;
    dfs(i, 1);
    if (!ok) { ans[1] = INF; break; }

    ans[1] += min(szc, sz-szc);

    if (szc < sz-szc) for (int v : tmp[1]) vans[1].pb(v);
    else for (int v : tmp[0]) vans[1].pb(v);
  }

  if (ans[0] > n and ans[1] > n) return 0*printf("-1\n");

  int b = 0;
  if (ans[1] < ans[0]) b = 1;

  printf("%d\n", ans[b]);
  for (int v : vans[b]) printf("%d ", v);
  printf("\n");

  return 0;
}
