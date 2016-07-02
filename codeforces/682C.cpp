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

const ld EPS = 1e-6, PI = acos(-1);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, a[N], x, y;
vi adj[N], adjw[N];
int dist[N], vis[N], rem[N], tam[N];
int ans;

void dfs(int u) {
  vis[u]=1;
  tam[u]=1;
  int t = 0;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    int w = adjw[u][i];
    if (vis[v]) continue;
    dist[v] = max(w, w+dist[u]);
    dfs(v);
    tam[u]+=tam[v];
    t += rem[v];
  }

  rem[u] = a[u]<dist[u];
}

void ndfs(int u) {
  vis[u]=1;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    int w = adjw[u][i];
    if (vis[v]) continue;

    if (rem[v]) ans += tam[v], vis[v];
    else ndfs(v);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i<=n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i<n; ++i) {
    scanf("%d%d", &x, &y);
    adj[i+1].pb(x); adjw[i+1].pb(y);
    adj[x].pb(i+1); adjw[x].pb(y);
  }

  dfs(1);
  cl(vis,0);
  ndfs(1);

  printf("%d\n", ans);

  return 0;
}
