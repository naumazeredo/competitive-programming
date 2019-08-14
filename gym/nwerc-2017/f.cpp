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
const int N = 105;

int cmp(ld a, ld b) { return (a > b+EPS) - (a < b-EPS); }

struct pt { ld x, y; pt(ld a = 0, ld b = 0) : x{a}, y{b} {} };
bool operator<(pt a, pt b){ return cmp(a.x, b.x) < 0 or (cmp(a.x, b.x) == 0 and cmp(a.y, b.y) < 0); }
bool operator==(pt a, pt b){ return cmp(a.x, b.x) == 0 and cmp(a.y, b.y) == 0; }
pt operator-(pt a, pt b){ return {a.x-b.x, a.y-b.y}; }
pt operator+(pt a, pt b){ return {a.x+b.x, a.y+b.y}; }
pt operator-(pt a){ return {-a.x, -a.y}; }
ld operator%(pt a, pt b) { return a.x*b.y - b.x*a.y; }
pt operator*(pt a, ld k){ return {k*a.x, k*a.y}; }

int n, x[N], y[N];
int ans;

bool collinear(pt a, pt b, pt c) { return cmp((b-a) % (c-a), 0) == 0; }
pt circumcircle(pt a, pt b, pt c) {
  pt ans;
  pt u = {(b-a).y, -(b-a).x};
  pt v = {(c-a).y, -(c-a).x};
  pt n = (c-b)*0.5;
  ld t = (u % n) / (v % u);
  ans = ((a+c)*0.5) + (v*t);
  return ans;
}

ld dist(ld x, ld y) { return sqrt(x*x+y*y); }

void calc2(int a, int b) {
  ld xx = (x[a] + x[b])*0.5;
  ld yy = (y[a] + y[b])*0.5;

  vector<ld> s;
  for (int i = 0; i < n; i++) s.push_back(dist(x[i]-xx, y[i]-yy));
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end(), [](ld a, ld b){ return cmp(a, b)==0; }), s.end());
  ans = min(ans, (int)s.size());
}

void calc3(int a, int b, int c) {
  pt pa = pt(x[a], y[a]), pb = pt(x[b], y[b]), pc = pt(x[c], y[c]);
  if (collinear(pa, pb, pc)) return;
  if (cmp((pc-pa) % (pb-pa), 0) > 0) swap(pb, pc);

  auto p = circumcircle(pa, pb, pc);
  ld xx = p.x;
  ld yy = p.y;
  db(a _ b  _ c);
  db(xx _ yy);

  vector<ld> s;
  for (int i = 0; i < n; i++) s.push_back(dist(x[i]-xx, y[i]-yy));
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end(), [](ld a, ld b){ return cmp(a, b)==0; }), s.end());
  ans = min(ans, (int)s.size());
  for (auto p : s) db(p);
  dbs("");
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
  ans = n;

  //for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) calc2(i, j);
  for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) for (int k = j+1; k < n; k++) calc3(i, j, k);
  printf("%d\n", ans);
  return 0;
}
