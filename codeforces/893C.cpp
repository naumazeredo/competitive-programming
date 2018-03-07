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
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m, c[N], x, y, mn, vis[N];
vi adj[N];

void dfs(int u) {
  vis[u] = 1;
  mn = min(mn, c[u]);
  for (int v : adj[u]) if (!vis[v]) dfs(v);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    adj[x].pb(y), adj[y].pb(x);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) if (!vis[i]) {
    mn = INF;
    dfs(i);
    ans += mn;
  }
  printf("%lld\n", ans);

  return 0;
}
