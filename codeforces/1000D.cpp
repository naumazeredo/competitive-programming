// @subject: dp
// @diff: 3

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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 1e3+5;

int n, a[N], dp[2][N];

ll add(ll a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) dp[1][j] = dp[0][j];
    if (a[i] > 0 and a[i] < n) dp[1][a[i]] = add(dp[1][a[i]], add(dp[0][0], 1));
    for (int j = 0; j < n; j++) dp[1][j] = add(dp[1][j], dp[0][j+1]);
    swap(dp[0], dp[1]);
  }

  printf("%d\n", dp[0][0]);

  return 0;
}
