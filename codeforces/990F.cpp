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
const int N = 2e5+5;

int n, s[N], m, vis[N];
vector<piii> adj[N];
ll ans[N];
ll sum;

void pre(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  sum += s[u];
  for (auto x : adj[u]) pre(x.st);
}

void dfs(int u, ll& t) {
  vis[u] = 1;
  t -= s[u];
  for (auto x : adj[u]) if (!vis[x.st]) {
    int v = x.st;
    int edge = x.nd.st;
    ll dir = x.nd.nd;

    ans[edge] += dir * t;
    dfs(v, t);
    ans[edge] -= dir * t;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);

  scanf("%d", &m);
  for (int x, y, i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    adj[x].push_back({ y, { i, 1 } });
    adj[y].push_back({ x, { i, -1 } });
  }

  for (int u = 1; u <= n; u++) if (!vis[u]) {
    sum = 0;
    pre(u);
    if (sum) return !printf("Impossible\n");
  }

  memset(vis, 0, sizeof vis);
  ll tot = 0;
  for (int u = 1; u <= n; u++) if (!vis[u]) dfs(u, tot);

  printf("Possible\n");
  for (int i = 0; i < m; i++) printf("%lld\n", ans[i]);

  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  return 0;
}
