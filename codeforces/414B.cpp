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
const int N = 2e3+5;

int n, k;
ll dp[N][N];

int main() {
  scanf("%d%d", &n, &k);

  for (int i = 1; i <= n; ++i) dp[1][i] = 1;
  for (int i = 2; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int l = 1; l*l <= j; ++l) if (j%l == 0) {
        dp[i][j] = (dp[i][j] + dp[i-1][l])%MOD;
        if (l*l != j) dp[i][j] = (dp[i][j] + dp[i-1][j/l])%MOD;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) ans = (ans + dp[k][i])%MOD;

  printf("%lld\n", ans);

  return 0;
}
