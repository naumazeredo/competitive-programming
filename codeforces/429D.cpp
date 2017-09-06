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
  #define db(x)
  #define dbs(x)
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

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

struct point {
  ll x, y;

  point() : x(0), y(0) {}
  point(ld x, ld y) : x(x), y(y) {}

  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  point operator *(ld k) { return point(k*x, k*y); }
  point operator /(ld k) { return point(x/k, y/k); }

  ll operator *(point p) { return x*p.x + y*p.y; }
  ll operator %(point p) { return x*p.y - y*p.x; }

  // o is the origin, p is another point
  // dir == +1 => p is clockwise from this
  // dir ==  0 => p is colinear with this
  // dir == -1 => p is counterclockwise from this
  int dir(point o, point p) {
    ll x = (*this - o) % (p - o);
    return ge(x,0) - le(x,0);
  }

  bool on_seg(point p, point q) {
    if (this->dir(p, q)) return 0;
    return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and
           ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
  }

  ll abs() { return sqrt(x*x + y*y); }
  ll abs2() { return x*x + y*y; }
  ll dist(point x) { return (*this - x).abs(); }
  ll dist2(point x) { return (*this - x).abs2(); }

  point project(point y) { return y * ((*this * y) / (y * y)); }
};

int n, a[N];
ll s[N];
point p[N];

ll closest_pair_util(point p[], int n) {
  if (n <= 3) {
    ll ans = p[0].dist2(p[1]);
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++)
      ans = min(ans, p[i].dist2(p[j]));
    return ans;
  }

  int mid = n/2;
  point mp = p[mid];
  ll d = min(closest_pair_util(p, mid), closest_pair_util(p+mid, n-mid));

  point strip[n];
  int sz = 0;
  for (int i = 0; i < n; i++) if ((p[i].x - mp.x)*(p[i].x - mp.x) < d) strip[sz++] = p[i];

  sort(strip, strip+sz, [](point s, point t){ return s.y > t.y; });
  for (int i = 0; i < sz; i++) for (int j = i+1; j < sz and (strip[i].y - strip[j].y)*(strip[i].y - strip[j].y) < d; j++)
    d = min(d, strip[i].dist2(strip[j]));

  return d;
}

ll closest_pair(point p[], int n) {
  sort(p, p+n, [](point s, point t){ return s.x < t.x; });
  return closest_pair_util(p, n);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), s[i] = s[i-1]+a[i], p[i] = point(i, s[i]);
  printf("%lld\n", closest_pair(p, n));
  return 0;
}
