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
const int N = 1e5+5;

int a[3], na[3], n, p[N];
ll ans;

ll dist(ll x0, ll x1) { return abs(x0-x1); }

int main() {
  pii k[3];
  for (int i = 0; i < 3; i++) scanf("%d%d", &k[i].st, &k[i].nd);
  sort(k,k+3);
  for (int i = 0; i < 3; i++) a[i] = k[i].st, na[i] = k[i].nd;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  sort(p,p+n);

  int l = 0, r = n-1;
  for (; l < n and dist(p[l], a[0]) < dist(p[l], a[1]) and na[0]; l++, na[0]--) ans += dist(p[l], a[0]);
  for (; r >= l and dist(p[r], a[2]) < dist(p[r], a[1]) and na[2]; r--, na[2]--) ans += dist(p[r], a[2]);
  for (int i = l; i <= r; i++) ans += dist(p[i], a[1]);

  while (l <= r and r-l+1 > na[1]) {
    ll d0 = dist(p[l], a[0])-dist(p[l], a[1]);
    ll d2 = dist(p[r], a[2])-dist(p[r], a[1]);

    if (na[0] and na[2]) {
      if (d0 < d2) ans += d0, l++, na[0]--;
      else ans += d2, r--, na[2]--;
    } else if (na[0]) {
      ans += d0, l++, na[0]--;
    } else if (na[2]) {
      ans += d2, r--, na[2]--;
    } else {
      assert(0);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
