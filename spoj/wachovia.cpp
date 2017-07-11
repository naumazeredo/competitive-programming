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
const int N = 1e2+5;

int t, k, n, w[N], v[N], dp[N][1005];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &k, &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &w[i], &v[i]);

    cl(dp,0);
    for (int i = w[0]; i <= k; ++i) dp[0][i] = v[0];
    for (int i = 1; i < n; ++i) for (int j = 1; j <= k; ++j) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if (j >= w[i]) dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j-w[i]]);
    }

    printf("Hey stupid robber, you can get %d.\n", dp[n-1][k]);
  }
  return 0;
}
