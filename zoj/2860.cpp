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
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e3+5;

int v[N];

// 1) dp[i][j] = min i<k<j { dp[i][k] + dp[k][j] } + C[i][j]
int n, m;
ll dp[N][N], a[N][N];

// declare the cost function
int cost(int i, int j) { return v[j] - v[i]; }

void knuth() {
  // calculate base cases
  cl(dp, 63);
  for (int i = 0; i <= m+1; i++) {
    dp[i][i] = dp[i][i+1] = 0;
    a[i][i] = a[i][i+1] = i;
  }

  for (int j = 1; j <= m+1; ++j)
    for (int i = j-2; i >= 0; --i) {
      for (int k = a[i][j-1]; k <= a[i+1][j]; ++k) {
        ll v = dp[i][k] + dp[k][j] + cost(i, j);

        // store the minimum answer for d[i][k]
        // in case of maximum, use v > dp[i][k]
        if (v < dp[i][j])
          a[i][j] = k, dp[i][j] = v;
      }
    }
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= m; i++) scanf("%d", &v[i]);
    v[m+1] = n;
    knuth();

    printf("%lld\n", dp[0][m+1]);
  }
  return 0;
}
