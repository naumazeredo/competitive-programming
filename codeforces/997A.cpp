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
const int N = 3e5+5;

int n, a[N], x, y;

int main() {
  scanf("%d%d%d", &n, &x, &y);
  int m = 1;
  scanf("%1d", &a[1]);
  for (int i = 2; i <= n; i++) {
    m++;
    scanf("%1d", &a[m]);
    if (a[m] == a[m-1]) m--;
  }

  if (a[m]) m--;
  if (a[1]) m--;

  ll a0 = (m+1)/2, a1 = m-a0;
  ll ans = 0;
  if (a0) ans = min(a1 * x + max(a0-a1, 0ll)*y, a0 * y);
  printf("%lld\n", ans);

  return 0;
}
