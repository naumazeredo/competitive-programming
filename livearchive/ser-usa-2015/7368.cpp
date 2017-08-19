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
const int N = 5e2+5;

int n, m, p[N], g[N][N], s[N], f[N], t[N], T[N];

vi adj[N];
int vis[N], x, b[N];

bool match(int u) {
  if (vis[u] == x) return 0;
  vis[u] = x;
  for (int v : adj[u])
    if (!b[v] or match(b[v])) return b[v] = u;
  return 0;
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    cl(b,0);
    for (int i = 1; i <= m; i++) adj[i].clear();

    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
      scanf("%d", &g[i][j]), g[i][j] += (i!=j)*p[j];
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &s[i], &f[i], &t[i]), T[i] = t[i] + g[s[i]][f[i]];

    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++)
      if (i != j and t[j] >= T[i] + g[f[i]][s[j]]) adj[i].pb(j);

    int ans = 0;
    for (int i = 1; i <= m; i++) x++, ans += match(i);
    printf("%d\n", m-ans);
  }
  return 0;
}
