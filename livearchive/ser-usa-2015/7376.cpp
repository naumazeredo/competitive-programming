#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-6, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

struct point {
  ld x, y;

  point() : x(0), y(0) {}
  point(ld x, ld y) : x(x), y(y) {}

  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  point operator *(ld k) { return point(k*x, k*y); }
  point operator /(ld k) { return point(x/k, y/k); }

  ld operator *(point p) { return x*p.x + y*p.y; }
  ld operator %(point p) { return x*p.y - y*p.x; }

  // o is the origin, p is another point
  // dir == +1 => p is clockwise from this
  // dir ==  0 => p is colinear with this
  // dir == -1 => p is counterclockwise from this
  int dir(point o, point p) {
    ld x = (*this - o) % (p - o);
    return (x > EPS) - (x < EPS);
  }

  bool on_seg(point p, point q) {
    if (this->dir(p, q)) return 0;
    return le(x, min(p.x, q.x)) and
           ge(x, max(p.x, q.x)) and
           le(y, min(p.y, q.y)) and
           ge(y, max(p.y, q.y));
  }

  ld abs() { return sqrt(x*x + y*y); }
  ld dist(point x) { return (*this - x).abs(); }

  point project(point y) { return y * ((*this * y) / (y * y)); }

  ld dist_line(point x, point y) {
    point t = *this-x;
    return dist(t.project(y-x) + x);
  }

  ld dist_seg(point x, point y) {
    return min(dist_line(x, y), min(dist(x), dist(y)));
  }

  point rotate(ld a) {
    return point(cos(a)*x-sin(a)*y, sin(a)*x+cos(a)*y);
  }

  point rotate(point p) { // rotate around the argument from vector p
    ld hyp = (p.x+p.y) * (p.x+p.y);
    ld c = p.x / hyp;
    ld s = p.y / hyp;
    return point(c*x-s*y, s*x+c*y);
  }
};

// ----------------------

int n, ans, g[N], gc;
double tx, ty;
point ps[N];
vector<point> k;
map<pii, vector<int>> m;

int sz[N], p[N], cc[N];
int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
void unite(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (sz[u] < sz[v]) swap(u, v);
  p[v] = u;
  sz[u] += sz[v];
}

pii f(point p) {
  int fx, fy;
  fx = p.x; fx/=2;
  fy = p.y; fy/=2;

  return {fx, fy};
}

int main() {
  while (~scanf("%d", &n)) {
    ans = 0;
    for (int i = 0; i < n; i++) sz[i] = 1, p[i] = i;
    k.clear(); m.clear();

    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &tx, &ty), ps[i] = { tx, ty };
      m[f(ps[i])].pb(i);
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
      if (i != j and ps[i].dist(ps[j]) < 2+EPS) unite(i, j);

    for (int i = 0; i < n; i++) cc[i] = find(i), ans = max(ans, sz[i]+1);

    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) if (cc[i] != cc[j] and ps[i].dist(ps[j]) < 4+EPS) {
      point m = (ps[i]+ps[j])/2;
      point l = ps[i] - ps[j];
      l = l.rotate(PI/2); l = l/l.abs();

      ld d = ps[i].dist(ps[j])/2;
      ld h = sqrt(4 - d*d);

      k.pb(m + l*h);
      k.pb(m - l*h);
    }

    for (point p : k) {
      gc++;
      int c = 1;
      pii fp = f(p);
      for (int i = -2; i <= 2; i++) for (int j = -2; j <= 2; j++) for (int v : m[{fp.st+i, fp.nd+j}])
        if (g[cc[v]] != gc and p.dist(ps[v]) < 2+EPS) g[cc[v]] = gc, c+=sz[cc[v]];
      ans = max(ans, c);
    }

    printf("%d\n", ans);
  }
  return 0;
}
