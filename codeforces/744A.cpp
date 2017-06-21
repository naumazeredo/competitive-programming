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
const int N = 1e3+5;

int n, m, k, c[N], vis[N], a, b, sz[N];
vi adj[N];

void dfs(int u, int x) {
  vis[u] = 1;
  sz[x]++;

  for (int v : adj[u]) if (!vis[v]) dfs(v, x);
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) scanf("%d", &c[i]);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  }

  ll ans = 0;
  int t = 0, b = 0;
  for (int i = 0; i < k; ++i) {
    dfs(c[i], i);
    b = max(b, sz[i]);
    t += sz[i];
    ans += sz[i]*(sz[i]-1)/2;
  }
  t = n-t;

  ans += t*(t-1)/2 + t*b;

  printf("%lld\n", ans-m);

  return 0;
}
