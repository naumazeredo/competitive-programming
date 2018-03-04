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
const int N = 1e5+5, M = 3e7+5;

int n, m, a, b, v[N];
int ans;

int dp[N], lisl[N], lisr[N], lis;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d%d", &a, &b), v[a]++, v[b+1]--;
  for (int i = 1; i <= m; i++) v[i] += v[i-1];

  memset(dp, 63, sizeof dp);
  for (int i = 1; i <= m; i++) {
    int j = upper_bound(dp, dp+lis, v[i]) - dp;
    dp[j] = min(dp[j], v[i]);
    lis = max(lis, j+1);
    lisl[i] = lis;
  }

  lis = 0;
  memset(dp, 63, sizeof dp);
  for (int i = m; i >= 1; i--) {
    int j = upper_bound(dp, dp+lis, v[i]) - dp;
    dp[j] = min(dp[j], v[i]);
    lis = max(lis, j+1);
    lisr[i] = lis;
  }

  for (int i = 0; i <= m; i++) ans = max(ans, lisl[i] + lisr[i+1]);

  printf("%d\n", ans);

  return 0;
}
