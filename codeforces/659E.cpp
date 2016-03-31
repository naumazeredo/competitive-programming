#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, m, x, y;
vi adj[222222];
int inc[222222];

int cyc[222222];
int vis[222222];

int dfs(int u, int p) {
  vis[u] = 1;

  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v == p) continue;
    if (vis[v] == 1) cyc[u] = 1;
    else if (vis[v] == 2) cyc[u] = 1;
    else cyc[u] = max(cyc[u], dfs(v, u));
  }

  vis[u] = 2;
  return cyc[u];
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i)
    scanf("%d%d", &x, &y), adj[x].pb(y), adj[y].pb(x), inc[x]++, inc[y]++;

  queue<int> q;
  for (int i = 1; i <= n; ++i) if (inc[i]<=1) q.push(i);

  int t = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (vis[u]) continue;
    if (!dfs(u, 0)) t++;
  }

  printf("%d\n", t);

  return 0;
}
