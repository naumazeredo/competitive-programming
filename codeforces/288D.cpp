// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

ll n, dp[4], sz[N], ans;
vector<int> adj[N];

void dfs(int u, int p) {
  sz[u] = 1;
  for (int v : adj[u]) if (v != p) {
    dfs(v, u);
    sz[u] += sz[v];
  }

  vector<int> s;
  s.push_back(0);
  s.push_back(n-sz[u]);
  for (int v : adj[u]) if (v != p) s.push_back(sz[v]);

  memset(dp, 0, sizeof dp);
  for (int i = 1; i < (int)s.size(); i++) {
    if (i > 3) dp[3] += dp[2] * s[i];
    if (i > 2) dp[2] += dp[1] * s[i];
    if (i > 1) dp[1] += dp[0] * s[i];
    dp[0] += s[i];
  }
  db(u _ dp[0] _ dp[1] _ dp[2] _ dp[3]);

  ans -= dp[3] + dp[2];
}

int main() {
  scanf("%lld", &n);
  if (n < 4) return !printf("0\n");

  for (int a, b, i = 1; i <= n-1; i++) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  ans = 1;
  for (int i = 1; i <= 4; i++) {
    ans *= (n-i+1);
    ans /= i;
  }

  dfs(1, 0);

  printf("%lld\n", 2*ans);

  return 0;
}
