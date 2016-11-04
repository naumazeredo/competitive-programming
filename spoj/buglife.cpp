// template
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
const int N = 4e3+5;

int t, n, m, a, b, x[N];

// Kosaraju - SCC O(V+E)
vi adj[N], adjt[N];
int ord[N], ordn, scc[N], sccn;
int vis[N];

void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) if (!vis[v]) dfs(v);
  ord[ordn++] = u;
}

void dfst(int u) {
  vis[u] = 0;
  for (int v : adjt[u]) if (vis[v]) dfst(v);
  scc[u] = sccn;
}

/*
void sat(int u) {
  x[u] = 1; x[u^1] = 0;
  for (int v : adj[u]) if (x[v] == -1)
    sat(v);
}
*/

int main() {
  scanf("%d", &t);

  for (int tt = 1; tt <= t; ++tt) {
    scanf("%d%d", &n, &m);
    n*=2;
    for (int i = 0; i < n; ++i) adj[i].clear(), adjt[i].clear();
    cl(vis,0);

    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &a, &b);
      a--; b--;
      a*=2; b*=2;
      adj[a^1].pb(b); adjt[b].pb(a^1);
      adj[b^1].pb(a); adjt[a].pb(b^1);
      adj[b].pb(a^1); adjt[a^1].pb(b);
      adj[a].pb(b^1); adjt[b^1].pb(a);
    }

    sccn = ordn = 0;
    for (int i = 0; i < n; ++i) if (!vis[i]) dfs(i);
    for (int i = n-1; i >= 0; --i) if (vis[ord[i]]) dfst(ord[i]), sccn++;

    // 2-sat
    /*
    cl(x, -1);
    for (int i = 0; i < n; ++i) if (x[i] == -1)
      sat(scc[i] > scc[i^1] ? i : i^1);
      */

    int ok = 1;
    for (int i = 0; i < n; ++i) if (scc[i] == scc[i^1]) ok = 0;

    printf("Scenario #%d:\n%suspicious bugs found!\n", tt, ok?"No s":"S");
  }

  return 0;
}
