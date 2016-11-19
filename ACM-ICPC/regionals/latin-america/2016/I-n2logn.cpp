/**
  !!! WARNING !!!

  This is not the correct solution! It will receive Time Lime Exceed evaluation!

  reference (pt-br): https://algorithmmarch.wordpress.com/2016/08/12/a-otimizacao-de-pds-e-o-garcom-da-maratona/
**/

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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int N = 6e3+5;

int n, b, c;
ll h[N], p[N], s[N], dp[N][N], ans[N], x[N][N];

ll costasc(int l, int r) { return c * (p[r] - p[l-1] - l * (s[r] - s[l-1])); }
ll costdes(int l, int r) { return c * (r * (s[r] - s[l-1]) - (p[r] - p[l-1])); }
ll cost(int l, int r)    { return costasc(l, (l+r)/2) + costdes((l+r)/2+1, r); }

void calc(int l, int r, int k, int imin, int imax) {
  int m = (l+r)/2;
  dp[m][k] = LINF;
  for (int i = imin; i <= imax and i < m; ++i) {
    ll v = dp[i][k-1] + cost(i, m) + b;
    if (dp[m][k] > v)
      x[m][k] = i, dp[m][k] = v;
  }

  if (l < r) {
    calc(l, (l+r)/2, k, imin, x[m][k]);
    calc((l+r)/2+1, r, k, x[m][k], imax);
  }
}

int main() {
  scanf("%d%d%d", &n, &b, &c);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &h[i]);
    s[i] = s[i-1]+h[i];
    p[i] = p[i-1]+i*h[i];
  }

  cl(dp, 63);
  for (int i = 1; i <= n; ++i)
    dp[i][1] = costdes(1, i) + b;

  for (int k = 2; k <= n; ++k)
    calc(1, n, k, 1, n);

  cl(ans, 63);
  for (int k = 1; k <= n; ++k)
    for (int i = k; i <= n; ++i)
      ans[k] = min(ans[k], dp[i][k] + costasc(i, n));

  for (int k = 1; k <= n; ++k)
    printf("%lld%c", ans[k], k==n?'\n':' ');

  return 0;
}
