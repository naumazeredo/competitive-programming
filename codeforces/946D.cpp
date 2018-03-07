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
const int N = 5e2+5;

int n, m, k;
int l[N][N], p[N][N], cl[N];
int dp[N][N];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++)
      scanf("%1d", &l[i][j]),
      cl[i] += l[i][j];

  memset(p, 63, sizeof p);

  for (int i = 1; i <= n; i++) {
    p[i][cl[i]] = 0;
    for (int a = 0; a < m; a++) if (l[i][a]) {
      int t = 0;
      for (int b = a; b < m; b++) if (l[i][b]) {
        t++;
        int c = cl[i]-t;
        p[i][c] = min(p[i][c], b-a+1);
      }
    }
  }

  memset(dp, 63, sizeof dp);
  dp[0][k] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
      for (int a = 0; a <= min(cl[i], j); a++)
        dp[i][j-a] = min(dp[i][j-a], dp[i-1][j] + p[i][a]);

  int ans = INF;
  for (int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);

  printf("%d\n", ans);

  return 0;
}
