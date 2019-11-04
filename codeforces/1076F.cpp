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
const int N = 3e5+5;

int n, k, v[N][2];
pii dp[N][2];

void update(int i, int s, int v) {
  dp[i][s].st = min(dp[i][s].st, v);
  dp[i][s].nd = max(dp[i][s].nd, v);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i][0]);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i][1]);

  for (int i = 1; i <= n; i++) dp[i][0] = { -INF, INF }, dp[i][1] = { -INF, INF };

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      if (v[i][j] == 0 and dp[i-1][1-j].st >= 0 and dp[i-1][1-j].st + v[i][1-j] <= k)
        update(i, 1, dp[i-1][1-j].st + v[i][1-j]);

      int pre = 
    }

    /*
    int other = v[i][1-s];
    int val = v[i][1-s];

    int pre = dp[i-1][s];
    if (pre == -1 and dp[i-1][1-s] != -1) pre = 0;
    if (pre == -1) continue;

    if (pre and other) {
      val -= k-x; other -= 1
    } else {
    }
    */
  }

  return 0;
}
