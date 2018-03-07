#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e5+5;

ll r, x[2], y[2];

ll sq(ll a) { return a*a; }

int main() {
  scanf("%lld%lld%lld%lld%lld", &r, &x[0], &y[0], &x[1], &y[1]);

  if (sq(r) <= sq(x[0]-x[1]) + sq(y[0]-y[1]))
    return printf("%lld %lld %lld\n", x[0], y[0], r), 0;

  if (x[0] == x[1] and y[0] == y[1]) {
    ld cx = x[0]+r/2.0L;
    ld cy = y[0];
    ld rad = r/2.0L;
    printf("%.12Lf %.12Lf %.12Lf\n", cx, cy, rad);
    return 0;
  }

  ld dx = x[0] - x[1];
  ld dy = y[0] - y[1];
  ld norm = sqrt(sq(dx)+sq(dy));

  dx /= norm; dy /= norm;
  dx *= r; dy *= r;
  dx += x[0]; dy += y[0];

  ld cx = (dx+x[1])/2;
  ld cy = (dy+y[1])/2;
  ld rad = (norm + r)/2;

  printf("%.12Lf %.12Lf %.12Lf\n", cx, cy, rad);

  return 0;
}
