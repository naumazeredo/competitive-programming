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

int n, u, v, c[N], cnt[2];
vi adj[N];

void dfs(int u) {
  cnt[c[u]]++;
  for (int v : adj[u]) if (c[v]==-1) c[v]=1-c[u], dfs(v);
}

int main() {
  cl(c,-1);
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++) scanf("%d%d", &u, &v), adj[u].pb(v), adj[v].pb(u);

  c[1] = 0;
  dfs(1);

  ll ans = 0;
  for (int i = 1; i <= n; i++) ans += cnt[1-c[i]]-adj[i].size();
  printf("%lld\n", ans/2);
  return 0;
}
