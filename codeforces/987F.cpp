// @subject: 
// @diff: 

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = 1<<22;

int n, m, a[N], h[N], sz[N], par[N], vis[N];
int g[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }
void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  par[b] = a;
}

void dfs(int u, int k) {
  vis[u] = 1;

  if (h[u]) {
    unite(u, k);
    g[u] = u;
  }

  for (int i = 0; i < n; i++) if (u&(1<<i)) {
    int v = u-(1<<i);
    if (!vis[v]) dfs(v, k);
    if (~g[v]) unite(k, g[v]);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    h[a[i]] = 1;
    sz[a[i]] = 1; par[a[i]] = a[i];
  }

  memset(g, -1, sizeof g);
  for (int i = 0; i < m; i++) dfs((1<<n)-1 - a[i], a[i]);

  int ans = 0;
  for (int i = 0; i < (1<<n); i++) if (h[i] and par[i] == i)
    ans++;

  printf("%d\n", ans);

  return 0;
}
