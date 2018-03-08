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

typedef ld type;

struct pt {
  type x, y;
  pt() : x(0), y(0) {}
  pt(type x, type y) : x(x), y(y) {}
  pt operator+(pt p) { return pt(x+p.x, y+p.y); }
  pt operator-(pt p) { return pt(x-p.x, y-p.y); }
  pt operator*(ld k) { return pt(x*k, y*k); }
  pt operator/(ld k) { return pt(x/k, y/k); }

  type operator*(pt p) { return x*p.x + y*p.y; }
  type operator%(pt p) { return x*p.y - y*p.x; }

  ld abs() { return sqrt(x*x+y*y); }
};

int vmax, t, x, y;
pt s, e, v, w;

bool solv(ld m) {
  pt a = s + v*min(1.0l*t, m) + w*max(0.0l, m-t);
  return (e-a).abs() < m*vmax + EPS;
}

int main() {
  scanf("%d%d", &x, &y); s = pt(x, y);
  scanf("%d%d", &x, &y); e = pt(x, y);
  scanf("%d%d", &vmax, &t);
  scanf("%d%d", &x, &y); v = pt(x, y);
  scanf("%d%d", &x, &y); w = pt(x, y);

  ld lo = 0, hi = 1e9;
  for (int i = 0; i < 100; i++) {
    ld md = (lo+hi)/2;
    if (solv(md)) hi = md;
    else lo = md;
  }
  printf("%.12Lf\n", lo);

  return 0;
}
