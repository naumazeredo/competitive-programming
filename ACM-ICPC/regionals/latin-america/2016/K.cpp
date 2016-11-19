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
const int N = 1e2+5;

int n, a[N], b[N], ans;
int adj[N][N], par[N], dist[N];
int s, t;

void add(int u, int v, int c) {
  adj[u][v] = c;
  adj[v][u] = 0;
}

int bfs() {
  cl(par,-1), cl(dist,63);
  queue<int> q;
  q.push(s);
  dist[s] = 0;

  while (q.size()) {
    int u = q.front(); q.pop();
    if (u == t) break;

    for (int v = 0; v <= 2*n+1; ++v) if (v != u and adj[u][v] > 0 and dist[v] > dist[u]+1)
      dist[v] = dist[u]+1, par[v] = u, q.push(v);
  }

  return dist[t]!=INF;
}

int edmondkarp() {
  int res = 0;
  while (bfs()) {
    int f = INF;
    int u = t;
    while (~par[u]) f = min(f, adj[par[u]][u]), u = par[u];
    res += f;

    u = t;
    while (~par[u]) adj[par[u]][u]-=f, adj[u][par[u]]+=f, u = par[u];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);

  s = 0, t = 2*n+1;
  for (int i = 1; i <= n; ++i) {
    cl(adj,0);

    int k = 0;
    for (int j = 1; j <= n; ++j)
      k += a[j]==i or b[j]==i;

    for (int j = 1; j <= n; ++j) if (j != i)
      add(s, j, 1);

    for (int j = 1; j <= n; ++j) if (j != i and a[j] != i and b[j] != i)
      add(j, n+a[j], 1), add(j, n+b[j], 1);

    for (int j = 1; j <= n; ++j) if (j != i)
      add(n+j, t, k-1-(a[i] == j or b[i] == j));

    ans += edmondkarp() == n-k-1;
  }

  printf("%d\n", n-ans);

  return 0;
}
