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

int t, n, m, a, b, vis[N];
set<int> adj[N];

int dfs(int u) {
  vis[u] = 1;

  int loop = 0;
  for (int v : adj[u]) {
    if (!vis[v]) if (dfs(v)) loop = 1;
    if (vis[v] == 1) loop = 1;
  }

  vis[u] = 2;
  return loop;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) adj[i].clear(), vis[i]=0;
    for (int i = 0; i < m; ++i) scanf("%d%d", &a, &b), adj[a].insert(b);

    int loop = 0;
    for (int i = 1; i <= n; ++i) if (!vis[i] and dfs(i)) loop = 1;
    printf("%s\n", loop?"SIM":"NAO");
  }
  return 0;
}
