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
const int N = 1e5+5;

int n, sz[N], p[N];
vi adj[N];

void dfs(int u) {
  sz[u] = 1;

  for (int v : adj[u]) if (!sz[v]) {
    dfs(v);
    sz[u] += sz[v];
  }
}

int main() {
  scanf("%d", &n);

  if (n%2) return !printf("-1\n");

  for (int u, v, i = 0; i < n-1; i++) {
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for (int i = 1; i <= n; i++) if (!sz[i]) dfs(i);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += sz[i]%2 == 0;

  if (ans == 0) printf("-1\n");
  else printf("%d\n", ans-1);

  return 0;
}
