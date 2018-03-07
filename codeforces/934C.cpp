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
const int N = 2e3+5;

int n, a[N];
int dp[N][N][3][3];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  for (int i = 1; i <= n; i++) {
    dp[i][i][1][1] = (a[i] == 1);
    dp[i][i][1][2] = 1;
    dp[i][i][2][1] = 1;
    dp[i][i][2][2] = (a[i] == 2);
    for (int j = i+1; j <= n; j++) {
      dp[i][j][1][1] = dp[i][j-1][1][1] + (a[j] == 1);
      dp[i][j][1][2] = max(dp[i][j-1][1][1] + 1, dp[i][j-1][1][2] + (a[j] == 2));
      dp[i][j][2][1] = max(dp[i][j-1][2][2] + 1, dp[i][j-1][2][1] + (a[j] == 1));
      dp[i][j][2][2] = dp[i][j-1][2][2] + (a[j] == 2);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      // 1 1 1/2
      ans = max(ans,
                dp[1][i-1][1][1] +
                dp[i][j][2][2] +
                max(dp[j+1][n][1][1], dp[j+1][n][1][2]));
      // 1/2 2 2
      ans = max(ans,
                max(dp[1][i-1][1][1], dp[1][i-1][1][2]) +
                dp[i][j][1][1] +
                dp[j+1][n][2][2]);

      // 1 1->2 2
      ans = max(ans,
                dp[1][i-1][1][1] +
                dp[i][j][2][1] +
                dp[j+1][n][2][2]);
    }
  }

  printf("%d\n", ans);

  return 0;
}
