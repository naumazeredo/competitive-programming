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

int t, n, m, a, b, c;
vi adj[N], adjt[N];
int order[N], ordern, scc[N], sccn;
int vis[N];

void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) if (!vis[v]) dfs(v);
  order[ordern++] = u;
}

void dfst(int u) {
  vis[u] = 0;
  for (int v : adjt[u]) if (vis[v]) dfst(v);
  scc[u] = sccn;
}

int main() {
  while (~scanf("%d%d", &n, &m) and n) {
    for (int i = 1; i <= n; ++i) adj[i].clear(), adjt[i].clear();
    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      adj[a].pb(b), adjt[b].pb(a);
      if (c == 2) adj[b].pb(a), adjt[a].pb(b);
    }

    sccn = ordern = 0;
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
    for (int i = n-1; i >= 0; --i) if (vis[order[i]]) dfst(order[i]), sccn++;

    printf("%d\n", sccn>1?0:1);
  }
  return 0;
}
