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

const ld PI = acos(-1.);
const ld EPS = 1e-18;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, xc, yc, v, t, x, y, r, op;
vector< pair<ld, int> > ang;

int main() {
  scanf("%d%d%d%d%d", &xc, &yc, &v, &t, &n);
  ld tt = 1.0L*v*t;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &r);
    x-=xc, y-=yc;

    ld nx = x, ny = y;

    ld dd = sqrt(1.0L*nx*nx+1.0L*ny*ny);
    ld dist = dd-r;
    ld r2 = 1.0L*r*r;

    if (dist < EPS) return 0*printf("1\n");
    if (dist < tt) {
      ld side = sqrt(dd*dd-r2);
      ld a;
      if (tt >= side) a = acos(side/dd);
      else a = acos((dd*dd+tt*tt-r2)/(2*dd*tt));
      ld ca = atan2(ny, nx);

      if (ca+a>EPS and ca-a<-EPS) op++;
      if (ca+a<EPS) ca+=2*PI;
      ang.pb(mp(ca+a-EPS, 1));
      ang.pb(mp(ca+2*PI+a-EPS, 1));

      if (ca-a<-EPS) ca+=2*PI;
      ang.pb(mp(ca-a+EPS, 0));
      ang.pb(mp(ca+2*PI-a+EPS, 0));
    }
  }

  sort(ang.begin(), ang.end());

  ld ans = 0;
  int i = 0, id;
  ld a = 0, ca = 0;
  while (i < ang.size() and ca-2*PI<-EPS) {
    ca = ang[i].st;
    id = ang[i].nd;
    if (op) ans += min(ca, 2*PI)-a;

    if (id) op--;
    else op++;

    a = ca;
    i++;
  }

  printf("%.9lf\n", (double)(ans/(2*PI)));

  return 0;
}
