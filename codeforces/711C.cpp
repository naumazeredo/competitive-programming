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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int N = 1e2+5;

int n, m, k, c[N], p[N][N];
ll dp[N][N][N];

ll go(int x, int g, int l) {
  if (c[x] and c[x] != l) return LINF;
  if (x == n and g == 0) return p[x][l];
  if (x == n or g < 0) return LINF;
  if (~dp[x][g][l]) return dp[x][g][l];

  ll ans = LINF;
  for (int i = 1; i <= m; ++i)
    ans = min(ans, p[x][l]+go(x+1,g-(l!=i),i));
  return dp[x][g][l] = ans;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
    scanf("%d", &p[i][j]);
    if (c[i]) p[i][j] = 0;
  }

  cl(dp,-1);
  ll ans = go(0, k, 0);

  printf("%lld\n", ans!=LINF?ans:-1);

  return 0;
}
