// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 1e5+5, M = 205, X = 200;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

int mul(int a, int b) {
  return 1ll*a*b%MOD;
}

int n, a[N];
int dp[N][M][2];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  for (int i = 1; i <= X; i++) dp[1][i][0] = (a[1] == -1 or a[1] == i);
  for (int i = 2; i <= n; i++) {
    int sum = 0;
    for (int k = 1; k <= X; k++) sum = add(sum, dp[i-1][k][1]);
    int acc = 0;

    for (int j = 1; j <= X; j++) {
      if (a[i] == -1 or a[i] == j) {
        dp[i][j][0] = add(dp[i][j][0], acc);

        dp[i][j][1] = add(dp[i][j][1], sum);
        dp[i][j][1] = add(dp[i][j][1], dp[i-1][j][0]);
      }

      //db(i _ j _ dp[i][j][0] _ dp[i][j][1]);
      sum = sub(sum, dp[i-1][j][1]);
      acc = add(acc, add(dp[i-1][j][0], dp[i-1][j][1]));
    }
    //dbs("");
  }

  int ans = 0;
  for (int i = 1; i <= 200; i++) ans = add(ans, dp[n][i][1]);
  printf("%d\n", ans);

  return 0;
}
