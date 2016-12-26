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
const int INF = 0x3f3f3f3f, MOD = 1e8;
const int N = 1e5+5;

int n1, n2, k1, k2, dp[200][200][20][20], ans;

int main() {
  scanf("%d%d%d%d", &n1, &n2, &k1, &k2);

  dp[0][0][0][0] = 1;
  for (int i = 0; i <= n1; ++i) for (int j = 0; j <= n2; ++j)
    for (int k = 0; k <= k1; ++k) for (int l = 0; l <= k2; ++l) {
      int v = dp[i][j][k][l];
      //db(i _ j _ k _ l _ v);
      if (i+j==n1+n2) ans = (ans + v)%MOD;
      if (i < n1 and k < k1) dp[i+1][j][k+1][0] = (dp[i+1][j][k+1][0]+v)%MOD;
      if (j < n2 and l < k2) dp[i][j+1][0][l+1] = (dp[i][j+1][0][l+1]+v)%MOD;
    }

  printf("%d\n", ans);
  return 0;
}
