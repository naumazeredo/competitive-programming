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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, m, q, dp[N];
char s[N], t[N];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  scanf("%s%s", s+1, t+1);
  for (int i = 1; i <= n-m+1; i++) {
    int ok = 1;
    for (int j = 1; j <= m and ok; j++)
      if (s[i+j-1] != t[j]) ok = 0;

    dp[i] = dp[i-1]+ok;
  }

  for (int l, r, i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    printf("%d\n", r>=l+m-1?dp[r-m+1]-dp[l-1]:0);
  }

  return 0;
}
