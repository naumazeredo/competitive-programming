// @subject: 
// @diff: 

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 6e5+5, M = 1e7+5;

int n, m, k, vis[N];
ll c[N];
map<ll, vector<pii>> edges;
map<ll, vector<int>> adj[N];
int cnt, sz[N];
int ans;

map<ll, set<int>> mx;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

int mul(int a, int b) {
  return 1ll*a*b % MOD;
}

int dfs(int u, ll x) {
  if (vis[u] == cnt) return 0;
  vis[u] = cnt;

  int s = 1;
  for (int v : adj[u][x]) s += dfs(v, x);
  return s;
}

ll fexp(ll a, ll b, ll m = MOD) {
  ll r=1;
  for (a %= m; b; b>>=1, a=(a*a)%m) if (b&1) r=(r*a)%m;
  return r;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
  for (int u, v, i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);

    ll x = c[u]^c[v];

    int e = edges.size();
    edges[x].push_back({ u, v });


    adj[u][x].push_back(e);
    adj[v][x].push_back(e);
  }

  ans = mul(fexp(2, n), fexp(2, k));

  for (auto p : edges) {
    ll x = p.st;
    auto s = p.nd;

    int sz = 0;
    int tot = 0;
    for (auto e : s) {
      cnt++;
      int a = dfs(e.st, x);
      tot += a;
      sz++;
    }

    tot = n - tot;
    ans -= mul(fexp(2, tot), fexp(2, sz+1));
  }

  printf("%d\n", ans);

  return 0;
}
