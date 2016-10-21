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

int n, m, c[N], v[N], a, b;
vi adj[N];
set<pii> vis;

int gcd(int a, int b) { return b?gcd(b,a%b):a; }

void dfs(int u, int g) {
  if (vis.count({u,g})) return;
  vis.insert({u,g});
  v[g] = 1;
  for (auto v : adj[u])
    dfs(v, gcd(g, c[v]));
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; ++i) adj[i].clear();
    cl(v,0);
    vis.clear();

    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < m; ++i) scanf("%d%d", &a, &b), adj[a].pb(b), adj[b].pb(a);

    for (int i = 1; i <= n; ++i) dfs(i, c[i]);

    int ans = 0;
    for (int i = 1; i < N; ++i) ans += v[i];
    printf("%d\n", ans);
  }
  return 0;
}
