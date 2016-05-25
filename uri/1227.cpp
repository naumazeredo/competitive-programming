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
const int N = 1e2+5;

vi adj[N];
int p[N], vis[N];
int v[N], lca, dist[2];

int n, a, d[2], x, y;

void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) if (!vis[v])
    p[v] = u, dfs(v);
}

int main() {
  while (~scanf("%d%d%d%d", &n, &a, &d[0], &d[1])) {
    cl(vis,0);
    cl(v, 0);
    for (int i = 0; i <= n; ++i) adj[i].clear();
    for (int i = 0; i < n-1; ++i) scanf("%d%d", &x, &y), adj[x].pb(y), adj[y].pb(x);

    p[a] = -1;
    dfs(a);

    int u = d[0];
    dist[0] = 0;
    while (~u) v[u]=++dist[0], u=p[u];

    u = d[1];
    dist[1] = 0;
    while (!v[u]) dist[1]++, u=p[u];
    dist[0]=v[u]-1;

    printf("%.6f\n", dist[1]/(double)(dist[0]+dist[1]));
  }
  return 0;
}
