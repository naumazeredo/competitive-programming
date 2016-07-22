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

int n, k, a, b, m[N], vis[N], sz[N];
vi adj[N];
ll ans;

void dfs(int u) {
  vis[u] = 1;
  if (m[u]) sz[u]=1;
  for (int v : adj[u]) if (!vis[v])
    dfs(v), sz[u]+=sz[v];
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < 2*k; ++i) scanf("%d", &a), m[a] = 1;
  for (int i = 0; i < n-1; ++i) {
    scanf("%d%d", &a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1);
  for (int i = 0; i <= n; ++i)
    ans += min(2*k-sz[i], sz[i]);

  printf("%lld\n", ans);
  return 0;
}
