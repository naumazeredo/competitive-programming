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

int n, a, b, c[N], p[N], vis[N], x[N], y[N], z[N];
vi adj[N];
int ans = 0;

int dfs(int u) {
  vis[u] = 1;

  int cnt = 0, ce = 0, k = 0, l = 0;
  for (int v : adj[u]) if (!vis[v]) {
    p[v] = u;
    int r = dfs(v);
    cnt += r;
    if (c[v] == c[u]) ce += r;
    if (!r or c[v] != c[u]) k++, l = v;
  }

  if (cnt == adj[u].size()-(u==1?0:1)) x[u] = 1;
  if (k == 1) y[u] = l;

  //db(u _ p[u] _ x[u] _ y[u]);

  return ce == adj[u].size()-(u==1?0:1);
}

void dfs2(int u) {
  //db(u _ p[u]);
  vis[u] = 0;

  if (!y[u] and !x[u]) return;

  if ((y[u] or x[u]) and (u == 1 or c[u] == c[p[u]])) z[u]=1;

  //db(z[u]);
  if (x[u] and z[p[u]]) { ans = u; return; }
  //db(y[u]);
  if (z[u]) dfs2(y[u]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d%d", &a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  }

  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);

  dfs(1);
  if (!x[1]) dfs2(1);
  else ans = 1;

  if (ans) printf("YES\n%d\n", ans);
  else printf("NO\n");

  return 0;
}
