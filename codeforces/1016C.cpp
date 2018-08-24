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

const int N = 3e5+5;

int n, a[2][N];
ll s[2][N];
ll ml[2][N], mr[2][N];

ll calc(int k, int i, ll t) {
  ll res = 0;

  res += t * (s[k][n] - s[k][i-1]);
  res += (ml[k][n] - ml[k][i-1]) - (i-1) * (s[k][n] - s[k][i-1]);

  res += (t + (n-(i-1))) * (s[k^1][n] - s[k^1][i-1]);
  res += mr[k^1][i];
  assert(res > 0);

  return res;
}

ll go(int k, int i, ll t) {
  if (i > n) return 0;
  ll res = max(a[k][i] * t + a[k^1][i] * (t+1) + go(k^1, i+1, t+2), calc(k, i, t));
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[0][i]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[1][i]);

  for (int i = 1; i <= n; i++) {
    s[0][i] = s[0][i-1] + a[0][i];
    s[1][i] = s[1][i-1] + a[1][i];
  }

  for (int i = 1; i <= n; i++) {
    ml[0][i] = ml[0][i-1] + 1ll*(i-1)*a[0][i];
    ml[1][i] = ml[1][i-1] + 1ll*(i-1)*a[1][i];
  }

  for (int i = n; i >= 1; i--) {
    mr[0][i] = mr[0][i+1] + 1ll*(n-i)*a[0][i];
    mr[1][i] = mr[1][i+1] + 1ll*(n-i)*a[1][i];
  }

  printf("%lld\n", go(0, 1, 0));

  return 0;
}
