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
const int N = 1e3+5;

int n, m, x, y, v[N][2], dp[N][2][N];
char c;

int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf(" %c", &c), v[j][0] += c=='.', v[j][1] += c=='#';

  cl(dp, 63);
  dp[0][0][1] = v[0][0];
  dp[0][1][1] = v[0][1];

  for (int i = 1; i < m; ++i)
    for (int j = 0; j < 2; ++j) {
      for (int k = 1; k <= min(y, m); ++k)
        dp[i][j][k+1] = min(dp[i][j][k+1], dp[i-1][j][k]   + v[i][j]);
      for (int k = x; k <= y; ++k)
        dp[i][j][1]   = min(dp[i][j][1],   dp[i-1][1-j][k] + v[i][j]);
    }

  /*
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 1; k <= m; ++k)
        db(i _ j _ k _ dp[i][j][k]);
        */

  int ans = INF;
  for (int j = 0; j < 2; ++j)
    for (int k = x; k <= y; ++k)
      ans = min(ans, dp[m-1][j][k]);

  printf("%d\n", ans);

  return 0;
}
