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

int n, k, c[N], ans[N], dp[2][N][N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);

  dp[0][0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    swap(dp[0], dp[1]);
    cl(dp[0],0);
    for (int j = 0; j <= k; ++j) for (int l = 0; l <= k; ++l) if (dp[1][j][l]) {
      dp[0][j][l] = 1;

      if (j+c[i] > k) continue;
      dp[0][j+c[i]][l] = 1;

      if (l+c[i] > k) continue;
      dp[0][j+c[i]][l+c[i]] = 1;
    }
  }

  for (int i = 0; i <= k; ++i) ans[i] = dp[0][k][i];

  int x = 0;
  for (int i = 0; i <= k; ++i) x+=ans[i];
  printf("%d\n", x);
  for (int i = 0; i <= k; ++i) if (ans[i]) printf("%d ", i);
  printf("\n");

  return 0;
}
