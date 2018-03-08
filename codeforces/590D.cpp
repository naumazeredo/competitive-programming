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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 155;

int n, k, s, a[N];
ll dp[N][N*N];

int main() {
  scanf("%d%d%d", &n, &k, &s);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  if (2*s > n*(n-1)) {
    sort(a+1, a+n+1);
    ll sum = 0;
    for (int i = 1; i <= k; i++) sum += a[i];
    printf("%lld\n", sum);
    return 0;
  }

  memset(dp, 63, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    /*
    dbs("");
    db(i);
    */
    for (int j = k; j >= 1; j--)
      for (int s = n*n; s >= i; s--)
        dp[j][s] = min(dp[j][s], dp[j-1][s-i] + a[i]);

    /*
    for (int j = 0; j <= k; j++)
      for (int s = 0; s <= n*n; s++)
        db(j _ s _ dp[j][s]);
    */
  }


  ll ans = LINF;
  for (int i = k*(k+1)/2; i <= k*(k+1)/2+s; i++) ans = min(ans, dp[k][i]);
  printf("%lld\n", ans);

  return 0;
}
