// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define y1 y1237857313

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

int n, x1, y1, x2, y2;
char s[N];

ll mx, my;

ll dist(ll a, ll b, ll x, ll y) {
  return abs(a-x) + abs(b-y);
}

int test(ll m) {
  ll px = x1, py = y1;
  px += (m/n)*mx;
  py += (m/n)*my;

  for (int i = 0; i < (m%n); i++) {
    if (s[i] == 'U') py++;
    if (s[i] == 'D') py--;
    if (s[i] == 'R') px++;
    if (s[i] == 'L') px--;
  }

  return dist(x2, y2, px, py) <= m;
}


int main() {
  scanf("%d%d", &x1, &y1);
  scanf("%d%d", &x2, &y2);
  scanf("%d%s", &n, s);

  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') my++;
    if (s[i] == 'D') my--;
    if (s[i] == 'R') mx++;
    if (s[i] == 'L') mx--;
  }

  ll lo = 0, hi = 1e15;
  while (lo < hi) {
    ll md = (lo+hi)/2;
    if (test(md)) hi = md;
    else lo = md+1;
  }

  printf("%lld\n", lo >= ll(1e14) ? -1 : lo);

  return 0;
}
