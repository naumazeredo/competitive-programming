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

int n, k, s, a[N], b[N], p[N];
int dp[N][N][10005];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);

  int total = accumulate(a+1, a+n+1, 0);
  vi v (b+1, b+n+1);
  sort(v.rbegin(), v.rend());
  for (k = 0, s = total; s > 0; s-=v[k++]);

  cl(dp,63);
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int s = 0; s <= total; ++s) {
        int& v = dp[i][j][s];
        v = min(v, dp[i-1][j][s] + a[i]);
        if (j) v = min(v, dp[i-1][j-1][max(0, s-b[i])]);
      }
    }
  }

  printf("%d %d\n", k, dp[n][k][total]);

  return 0;
}
