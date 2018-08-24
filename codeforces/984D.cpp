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
const int N = 5e3+5;

int n, a[N], q, l, r, dp[N][N], ans[N][N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  for (int i = 1; i <= n; i++) dp[i][1] = a[i];
  for (int s = 2; s <= n; s++) for (int i = 1; i <= n; i++)
    dp[i][s] = dp[i][s-1]^dp[i+1][s-1];

  for (int i = 1; i <= n; i++) ans[i][1] = dp[i][1];
  for (int s = 2; s <= n; s++) for (int i = 1; i <= n; i++)
    ans[i][s] = max(dp[i][s], max(ans[i][s-1], ans[i+1][s-1]));

  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    printf("%d\n", ans[l][r-l+1]);
  }
  return 0;
}
