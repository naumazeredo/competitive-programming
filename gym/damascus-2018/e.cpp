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
typedef pair<ld, ld> pld;
typedef vector<int> vi;

const ld EPS = 1e-7, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int t, n;
vector<pld> p;


int cmp(ld a, ld b = 0) { return (a > b + EPS) - (a < b - EPS); }
pld sub(pld a, pld b) { return { a.st - b.st, a.nd - b.nd }; }
pld add(pld a, pld b) { return { a.st + b.st, a.nd + b.nd }; }
ld cross(pld a, pld b) { return a.st*b.nd - a.nd*b.st; }
int ccw(pld a, pld b, pld c) { return cmp(cross(sub(a, b), sub(b, c))) >= 0; }
int line(pld a, pld b, pld c) { return cmp(cross(sub(a, b), sub(b, c))) == 0; }
ld norm(pld a) { return sqrt(a.st*a.st + a.nd*a.nd); }
pld cut(pld a, pld b, ld h) {
  pld ab = sub(b, a);

  ld abnorm = norm(ab);
  assert(cmp(abnorm) > 0);

  ab.st /= abnorm;
  ab.nd /= abnorm;
  assert(cmp(ab.nd) > 0);

  ld dh = h - a.nd;
  assert(cmp(dh) >= 0);

  ld k = dh / ab.nd;
  ab.st *= k;
  ab.nd *= k;

  return add(a, ab);
}

ld area(pld a, pld b, pld c) {
  ld res = a.st*b.nd + b.st*c.nd + c.st*a.nd;
  res -= a.nd*b.st + b.nd*c.st + c.nd*a.st;
  //return abs(res/2);
  return res/2;
}

ld solv() {
  /*
  dbs("-- solv --");
  for (pld b : p) db(b.st _ b.nd);
  */

  vector<pld> pts;

  int l = -1;
  ld h = 0;
  ld res = 0;
  for (pld a : p) {
    /*
    db(a.st _ a.nd _ h);
    for (auto b : pts) db(b.st _ b.nd);
    dbs("");
    */

    if (pts.size() >= 2) {
      while (pts.size() >= 2 and line(pts[pts.size()-2], pts[pts.size()-1], a)) pts.pop_back();
      if (cmp(a.nd, h) >= 0) {
        pld x = a;
        int nx = 0;
        if (cmp(a.nd, h) > 0)
          nx = 1, x = cut(pts.back(), a, h);
        //db(x.st _ x.nd);

        while ((int)pts.size() >= 2+l) {
        //while (pts.size() >= 2 and ccw(pts[pts.size()-2], pts[pts.size()-1], x)) {
          /*
          pld z = pts[pts.size()-2];
          pld y = pts[pts.size()-1];
          db(z.st _ z.nd _ y.st _ y.nd _ x.st _ x.nd _ area(z, y, x));
          */
          res += area(pts[pts.size()-2], pts[pts.size()-1], x);
          pts.pop_back();
        }

        if (nx) pts.push_back(x);
      }
    }
    //db(res);
    if (cmp(h, a.nd) < 0) h = a.nd, l = pts.size();
    pts.push_back(a);
    //dbs("");
  }

  p = pts;

  //db(res);

  return res;
}

ld ans() {
  ld last = 0;
  ld res = 0;
  do {
    last = res;
    res += solv();
    reverse(p.begin(), p.end());
    for (auto& a : p) a.st *= -1;
    res += solv();
    reverse(p.begin(), p.end());
    for (auto& a : p) a.st *= -1;
  } while (cmp(last, res) != 0);
  return res;

  /*
  ld res = 0;
  res += solv();
  reverse(p.begin(), p.end());
  for (auto& a : p) a.st *= -1;
  res += solv();
  return res;
  */
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    p.resize(n);
    for (int x, y, i = 0; i < n; i++) scanf("%d%d", &x, &y), p[i].st = x, p[i].nd = y;

    printf("%.9f\n", (double)ans());
  }
  return 0;
}
