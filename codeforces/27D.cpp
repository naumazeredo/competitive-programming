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
const int N = 4e2+5;

int n, m, a, b, l[N], r[N], x[N];

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

void sat(int u) {
  x[u] = 1; x[u^1] = 0;
  for (int v : adj[u]) if (x[v] == -1)
    sat(v);
}

int main() {
  scanf("%d%d", &n, &m);
  m*=2;
  for (int i = 0; i < m; ++i) adj[i].clear(), adjt[i].clear();

  for (int i = 0; i < m; i+=2) {
    scanf("%d%d", &a, &b);
    l[i] = min(a, b), r[i] = max(a, b);
    for (int j = 0; j < i; j+=2) {
      if ((l[j] > l[i] and l[j] < r[i] and !(r[j] >= l[i] and r[j] <= r[i])) or
          (r[j] > l[i] and r[j] < r[i] and !(l[j] >= l[i] and l[j] <= r[i]))) {
        adj[i^1].pb(j); adjt[j].pb(i^1);
        adj[j].pb(i^1); adjt[i^1].pb(j);

        adj[j^1].pb(i); adjt[i].pb(j^1);
        adj[i].pb(j^1); adjt[j^1].pb(i);
      }
    }
  }

  sccn = ordn = 0;
  for (int i = 0; i < m; ++i) if (!vis[i]) dfs(i);
  for (int i = m-1; i >= 0; --i) if (vis[ord[i]]) dfst(ord[i]), sccn++;

  int ok = 1;
  for (int i = 0; i < m; ++i) if (scc[i] == scc[i^1]) ok = 0;

  if (!ok) return 0*printf("Impossible\n");

  // 2-sat
  cl(x, -1);
  for (int i = 0; i < m; ++i) if (x[i] == -1)
    sat(scc[i] > scc[i^1] ? i : i^1);

  for (int i = 0; i < m; i+=2) printf("%c", x[i]?'i':'o');
  printf("\n");

  return 0;
}
