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

typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int cmp(ld a, ld b) {
  return (a > b-EPS) - (a < b+EPS);
}

struct pt {
  ll x, y;
  pt() : x(0), y(0) {}
  pt(int x, int y) : x(x), y(y) {}

  pt operator-() { return pt(-x, -y); }
  pt operator+(pt p) { return pt(x+p.x, y+p.y); }
  pt operator-(pt p) { return pt(x-p.x, y-p.y); }

  ll operator*(pt p) { return x*p.x+y*p.y; }
  ll operator%(pt p) { return x*p.y-y*p.x; }

  ll operator~() { return x*x+y*y; }
  ld operator!() { return sqrt(~(*this)); }
};

ld angle(pt v) {
  ld c = (pt(1, 0)*v)/(!v);
  ld s = (pt(1, 0)%v)/(!v);
  ld a = atan2(s, c);
  if (cmp(a, 0) < 0) a += 2*PI;

  return a;
}

ld get(pt v) {
  pt w (-v.y, v.x);
  if (v%w < 0) w = -w;
  return angle(w);
}

int n, q;
pt p[N], v;
set<pld> s;

void correct(pld& x) {
  while (cmp(x.st, 0) < 0) x.st += 2*PI;
  while (cmp(x.st, 2*PI) > 0) x.st -= 2*PI;

  while (cmp(x.nd, 0) < 0) x.nd += 2*PI;
  while (cmp(x.nd, 2*PI) > 0) x.nd -= 2*PI;
}

vector<pld> validate(pld x) {
  if (cmp(x.st, x.nd) <= 0) return { x };
  return { { x.st, 2*PI }, { 0, x.nd } };
}

void rem_interval(pld x) {
  correct(x);
  if (cmp(x.st, x.nd) > 0) {
    db(x.st _ x.nd _ cmp(x.st, x.nd));
    rem_interval({ x.st, 2*PI });
    rem_interval({ 0, x.nd });
    return;
  }

  vector<pld> rem, add;
  auto it = s.lower_bound(x);
  if (it != s.begin()) it--;
  for (; it != s.end(); it++) {
    if (cmp(x.st, it->nd) > 0) break;

    if (cmp(x.st, it->nd) < 0) add.push_back({ it->st, x.st+EPS });
    if (cmp(it->st, x.nd) < 0) add.push_back({ x.nd - EPS, it->nd });

    rem.push_back(*it);
  }

  db(x.st _ x.nd);
  for (auto v : rem) {
    for (auto w : validate(v))
      s.erase(w), db("rem" _ w.st _ w.nd);
  }
  for (auto v : add) {
    for (auto w : validate(v))
      s.insert(w), db("add" _ w.st _ w.nd);
  }
  printf("\n");
}

void preprocess() {
  s.insert({ 0, 2*PI });

  for (int i = 0; i < n; i++) if ((p[i+1]-p[i])%(p[i+2]-p[i+1]) < 0) {
    db(i);
    pld x;

    //x = { angle(p[i]-p[i+1]), angle(p[i+2]-p[i+1]) };
    ld a0 = get(p[i+2]-p[i+1]);
    ld a1 = get(p[i]-p[i+1]);
    db(a0 _ a1);
    x = { a0, a1 + PI};
    rem_interval(x);
    x = { a0+PI, a1+2*PI };
    rem_interval(x);
  }
}

int ans() {
  ld a = angle(v);
  db("ans" _ a);

  auto it = s.lower_bound({ a, 0 });
  if (it != s.begin()) it--;

  for (; it != s.end(); it++) {
    if (cmp(it->st, a) > 0) break;
    if (cmp(it->nd, a) > 0) return 1;
  }

  return 0;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
  p[n] = p[0];
  p[n+1] = p[1];

  preprocess();

  for (auto x : s) db(x.st _ x.nd);

  for (int i = 0; i < q; i++) {
    scanf("%lld%lld", &v.x, &v.y);
    printf("%c\n", ans() ? 'Y' : 'N');
  }

  return 0;
}
