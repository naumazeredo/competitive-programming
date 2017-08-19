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
const int N = 2e2+5;

int n, k, d, dp[N][N][2];

int main() {
  scanf("%d%d%d", &n, &k, &d);
  dp[0][0][0] = 1;
  for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int l = 0; l <= 1; l++) {
    for (int m = 1; m <  d; m++) dp[i+1][j+m][l] = (dp[i+1][j+m][l] + dp[i][j][l])%MOD;
    for (int m = d; m <= k; m++) dp[i+1][j+m][1] = (dp[i+1][j+m][1] + dp[i][j][l])%MOD;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + dp[i][n][1])%MOD;
  printf("%d\n", ans);

  return 0;
}
