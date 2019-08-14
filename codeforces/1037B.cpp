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
const int N = 2e5+5;

int n, s, a[N], h;

int main() {
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), h |= a[i] == s;
  sort(a, a+n);

  int cntl = 0, cntr = 0;
  ll ans = 0;
  for (int i = 0; i < n and a[i] < s; i++) {
    if (cntl == n/2) {
      ans += s-a[i];
    } else cntl++;
  }

  for (int i = n-1; i >= 0 and a[i] > s; i--) {
    if (cntr == n/2) {
      ans += a[i]-s;
    } else cntr++;
  }

  printf("%lld\n", ans);

  return 0;
}
