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
typedef pair<ll, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5, M = 1e4+5;

ll n, w, b, x;
ll c[N], cost[N], m;
ll dp[N][M];
ll ans;

int main() {
  scanf("%lld%lld%lld%lld", &n, &w, &b, &x);
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i]), m += c[i];
  for (int i = 1; i <= n; i++) scanf("%lld", &cost[i]);

  memset(dp, -1, sizeof dp);
  dp[0][0] = w;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j <= m; j++) {
      for (ll k = 0; k <= min(j, c[i]); k++) {
        if (dp[i-1][j-k] == -1) continue;

        ll v = min(dp[i-1][j-k] + x, w + (j-k)*b) - cost[i]*k;
        if (v < 0) continue;

        dp[i][j] = max(dp[i][j], min(v, w + j*b));

        ans = max(ans, j);
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
