/**
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

int main() {
  scanf("%d%d%d", &n, &b, &c);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &h[i]);
    s[i] = s[i-1]+h[i];
    p[i] = p[i-1]+i*h[i];
  }

  cl(dp, 63);
  for (int i = 1; i <= n; ++i) {
    assert(costdes(1, i) + b >= 0);
    dp[i][1] = costdes(1, i) + b,
    x[i][1] = 1, x[n+1][i] = n;
  }

  for (int k = 2; k <= n; ++k)
    for (int i = n; i >= k; --i)
      for (int j = x[i][k-1]; j <= x[i+1][k] and j < i; ++j) {
        ll v = dp[j][k-1] + cost(j, i) + b;
        if (dp[i][k] > v)
          x[i][k] = j, dp[i][k] = v;
      }

  cl(ans, 63);
  for (int k = 1; k <= n; ++k)
    for (int i = k; i <= n; ++i)
      ans[k] = min(ans[k], dp[i][k] + costasc(i, n));

  for (int k = 1; k <= n; ++k)
    printf("%lld%c", ans[k], k==n?'\n':' ');

  return 0;
}
