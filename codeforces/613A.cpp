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

const ld PI = acos(-1);

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

struct pt {
  ld x, y;
  pt operator+(pt a) { return {x+a.x, y+a.y}; }
  pt operator-(pt a) { return {x-a.x, y-a.y}; }
  pt operator*(ld c) { return {x*c, y*c}; }
  pt operator/(ld c) { return {x/c, y/c}; }
  ld operator*(pt a) { return x*a.x+y*a.y; }
  ld operator%(pt a) { return x*a.y-y*a.x; }
};

int n, x, y;
pt p[N];
ld dmax, dmin;

ld dist(pt a, pt b) { pt d = a-b; return sqrt(d.x*d.x+d.y*d.y); }
ld dist_seg(pt p, pt a, pt b) {
  ld d0 = (p-a)*(b-a);
  ld d1 = (p-b)*(a-b);
  if (d0 > 0 and d1 > 0) return dist(p, a+(b-a)*(d0/((b-a)*(b-a))));
  return min(dist(p,a), dist(p,b));
}

int main() {
  scanf("%d", &n);
  scanf("%d%d", &x, &y), p[0] = {x, y};
  for (int i = 1; i <= n; ++i) scanf("%d%d", &x, &y), p[i] = {x, y}, dmax = max(dmax, dist(p[0], p[i]));

  dmin = dist_seg(p[0], p[1], p[n]);
  db(dmin);
  for (int i = 1; i < n; ++i) dmin = min(dmin, dist_seg(p[0], p[i], p[i+1])), db(dmin);

  printf("%.9f\n", (float)(PI*(dmax*dmax-dmin*dmin)));

  return 0;
}
