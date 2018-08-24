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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, a, b;
int adj[N][N], adjc[N][N];
int vis[N];

void dfs(int u, int m[N][N]) {
  vis[u] = 1;
  for (int v = 0; v < n; v++) if (m[u][v] and !vis[v])
    dfs(v, m);
}

int main() {
  scanf("%d%d%d", &n, &a, &b);
  if (a != 1 and b != 1) return !printf("NO\n");

  int k = n-max(a,b);
  for (int i = 1; i <= k; i++) adj[i-1][i] = adj[i][i-1] = 1;

  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    adjc[i][j] = 1-adj[i][j];
  for (int i = 0; i < n; i++)
    adjc[i][i] = 0;

  if (b != 1) swap(adj, adjc);

  int ca = 0, cb = 0;
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++) if (!vis[i]) ca++, dfs(i, adj);
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++) if (!vis[i]) cb++, dfs(i, adjc);

  if (ca != a or cb != b) return !printf("NO\n");

  printf("YES\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) printf("%d", adj[i][j]);
    printf("\n");
  }

  return 0;
}
