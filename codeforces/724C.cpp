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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+5;

ll n, m, k;
ll x, y;
ll a, b, c;

// Extended Euclid: gcd(a, b) = x*a + y*b
void euclid(ll a, ll b, ll &x, ll &y, ll &d) {
  if (b) euclid(b, a%b, y, x, d), y -= x*(a/b);
  else x = 1, y = 0, d = a;
}

ll get() {
  ll dist = LINF;

  for (int i = -1; i <= 1; i++) if (i != 0)
    for (int j = -1; j <= 1; j++) if (j != 0)
      if ((((m+j*y)%m)-((n+i*x)%n)) % c == 0) {
        ll k = (((m+j*y)%m)-((n+i*x)%n)) / c;

        ll t = k*n;
        if (a < 0) t *= (a + m/c*((-a*c + m-1)/m));
        else t *= (a + m/c*(-(a*c)/m));

        t = (t%(m*n/c) + m*n/c)%(m*n/c);
        dist = min(dist, t+((n+i*x)%n));
      }

  return dist == LINF ? -1 : dist;
}

int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  n *= 2; m *= 2;

  euclid(n, m, a, b, c);

  for (int i = 0; i < k; i++) {
    scanf("%lld%lld", &x, &y);
    printf("%lld\n", get());
  }
  return 0;
}
