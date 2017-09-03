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
const int N = 2e5+5;

int n, a[N], p[N], x, y, ans[N];
vi adj[N];
set<int> s[N];

void dfs(int u, int g, int x) {
  if (x and s[u].count(g)) return;
  if (x) s[u].insert(g);

  int ng = __gcd(g, a[u]);
  ans[u] = max(ans[u], ng);
  if (!x) ans[u] = max(ans[u], g);
  for (int v : adj[u]) if (v != p[u]) {
    p[v] = u;
    dfs(v, ng, x);
    if (!x) dfs(v, g, 1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n-1; i++) scanf("%d%d", &x, &y), adj[x].pb(y), adj[y].pb(x);

  dfs(1, 0, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
