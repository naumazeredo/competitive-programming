// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const int N = 1e5+5;

int t;
ll l, r;
ll dp[20][10][4];

ll get(vector<int>& v, int n) {
  db(v.size() _ n);
  for (int x : v) db(x);

  if (n == 0) return 1;
  if (n == 1) {
    ll res = 0;
    for (int i = 0; i <= 3; i++) res += dp[0][v.back()][i];
    return res;
  }

  ll res = 0;
  if (v.back())
    for (int i = 0; i <= 2; i++) res += dp[n][v.back()-1][i];

  v.pop_back();
  res += get(v, n-1);

  return res;
}

ll get(ll x) {
  if (!x) return 0;
  vector<int> v;
  while (x) {
    v.push_back(x%10);
    x/=10;
  }
  return get(v, v.size());
}

int main() {
  dp[0][0][0] = 1;
  for (int i = 1; i <= 9; i++) dp[0][i][1] = 1;
  for (int i = 1; i < 20; i++) {
    // 0
    for (int k = 0; k <= 3; k++)
      for (int p = 0; p <= 9; p++)
        dp[i][0][k] += dp[i-1][p][k];

    // 1-9
    for (int j = 1; j <= 9; j++)
      for (int k = 1; k <= 3; k++) {
        dp[i][j][k] = dp[i][j-1][k];
        for (int p = 0; p <= 9; p++)
          dp[i][j][k] += dp[i-1][p][k-1];
      }
  }

  for (int i = 0; i <= 2; i++)
    for (int j = 0; j <= 9; j++)
      for (int k = 0; k <= 3; k++)
        db(i _ j _ k _ dp[i][j][k]);

  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", get(r)-get(l-1));
  }
  return 0;
}
