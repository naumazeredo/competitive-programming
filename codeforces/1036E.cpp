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
const int N = 1e3+5;

// Change long double to long long if using integers
typedef ll type;

bool ge(type x, type y) { return x >= y; }
bool le(type x, type y) { return x <= y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

struct point {
  type x, y;

  point() : x(0), y(0) {}
  point(type x, type y) : x(x), y(y) {}

  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  point operator *(type k) { return point(k*x, k*y); }
  point operator /(type k) { return point(x/k, y/k); }

  type operator *(point p) { return x*p.x + y*p.y; }
  type operator %(point p) { return x*p.y - y*p.x; }

  // o is the origin, p is another point
  // dir == +1 => p is clockwise from this
  // dir ==  0 => p is colinear with this
  // dir == -1 => p is counterclockwise from this
  int dir(point o, point p) {
    type x = (*this - o) % (p - o);
    return ge(x,0) - le(x,0);
  }

  bool on_seg(point p, point q) {
    if (this->dir(p, q)) return 0;
    return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and
           ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
  }
};


int direction(point o, point p, point q) { return p.dir(o, q); }

bool segments_intersect(point p, point q, point a, point b) {
  int d1, d2, d3, d4;
  d1 = direction(p, q, a);
  d2 = direction(p, q, b);
  d3 = direction(a, b, p);
  d4 = direction(a, b, q);
  if (d1*d2 < 0 and d3*d4 < 0) return 1;
  return p.on_seg(a, b) or q.on_seg(a, b) or
         a.on_seg(p, q) or b.on_seg(p, q);
}

point lines_intersect(point p, point q, point a, point b) {
  point r = q-p, s = b-a, c(p%q, a%b);
  if (eq(r%s,0)) return point(INF, INF);
  return point(point(r.x, s.x) % c, point(r.y, s.y) % c) / (r%s);
}

int n;
point a[N], b[N];
map<pll, int> rem;

ll ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld%lld%lld%lld", &a[i].x, &a[i].y, &b[i].x, &b[i].y);

  for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++)
    if (segments_intersect(a[i], b[i], a[j], b[j])) {
      point x = lines_intersect(a[i], b[i], a[j], b[j]);
      if (x.on_seg(a[i], b[i]) and x.on_seg(a[j], b[j]))
        rem[{ x.x, x.y }]++;
    }

  //for (auto p : rem) db(p.st.st _ p.st.nd _ p.nd);
  //for (auto p : rem) ans -= p.nd;
  for (auto p : rem) {
    ll v = 1+8*p.nd;

    ll sq = sqrt(v);
    while (sq*sq < v) sq++;
    while (sq*sq > v) sq--;

    ans -= (sq-1)/2;
  }

  for (int i = 1; i <= n; i++) {
    ll dx = abs(a[i].x - b[i].x);
    ll dy = abs(a[i].y - b[i].y);
    ll g = __gcd(dx, dy);
    dx /= g;
    dy /= g;

    if (dx) ans += abs(a[i].x-b[i].x) / dx + 1;
    else ans += abs(a[i].y-b[i].y) / dy + 1;
  }

  printf("%lld\n", ans);

  return 0;
}
