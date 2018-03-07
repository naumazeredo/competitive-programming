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

int n, m, a[N], b[N];
ll dp[N][3]; // 0 -> equal, 1 -> less, 2 -> greater

ll fexp(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b&1) r = (r*a)%MOD;
    a = (a*a)%MOD;
    b /= 2;
  }
  return r;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

  dp[0][0] = 1; dp[0][1] = 0; dp[0][2] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0 or b[i] == 0) {
      if (a[i] == b[i]) {
        dp[i][0] = (dp[i-1][0] * m) % MOD;
        dp[i][1] = (((dp[i-1][0] * ((1ll*(m-1)*m/2)%MOD))%MOD) + (((dp[i-1][1]*m)%MOD)*m)%MOD)%MOD;
        dp[i][2] = (((dp[i-1][0] * ((1ll*(m-1)*m/2)%MOD))%MOD) + (((dp[i-1][2]*m)%MOD)*m)%MOD)%MOD;
      } else if (a[i]) {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = ((dp[i-1][0]*(m-a[i]))%MOD + (dp[i-1][1]*m)%MOD)%MOD;
        dp[i][2] = ((dp[i-1][0]*(a[i]-1))%MOD + (dp[i-1][2]*m)%MOD)%MOD;
      } else {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = ((dp[i-1][0]*(b[i]-1))%MOD + (dp[i-1][1]*m)%MOD)%MOD;
        dp[i][2] = ((dp[i-1][0]*(m-b[i]))%MOD + (dp[i-1][2]*m)%MOD)%MOD;
      }
    } else if (a[i] == b[i]) {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      dp[i][2] = dp[i-1][2];
    } else {
      dp[i][0] = 0;
      dp[i][1] = (dp[i-1][1] + (a[i]<b[i]?dp[i-1][0]:0))%MOD;
      dp[i][2] = (dp[i-1][2] + (a[i]>b[i]?dp[i-1][0]:0))%MOD;
    }
  }

  ll q = 1;
  for (int i = 1; i <= n; i++) if (!a[i]) q = (q*m)%MOD;
  for (int i = 1; i <= n; i++) if (!b[i]) q = (q*m)%MOD;

  printf("%lld\n", (dp[n][2]*fexp(q, MOD-2))%MOD);

  return 0;
}
