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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n, m, a, cnt[N];
ll dp[N][4][4];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a), cnt[a]++;
  for (int i = 1; i <= m; i++) db(i _ cnt[i]);
  dbs("");

  for (int i = 0; i <= m+1; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        dp[i][j][k] = -INF;

  dp[1][0][0] = 0;
  for (int i = 1; i <= m; i++) {
    int c = cnt[i];
    for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++)
      for (int l = 0; l < 3 and j + k + l <= c; l++)
        dp[i+1][k][l] = max(dp[i+1][k][l], dp[i][j][k] + l + (c-j-k-l)/3);
  }

  printf("%lld\n", dp[m+1][0][0]);

  return 0;
}
