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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e3+5;

double cmp(double x, double y=0, double tol=EPS) { return (x <= y+tol) ? (x+tol > y) ? -1 : 0 : 1; }

//typedef complex<double> pt;
#define pt complex<double>

double dot(pt a, pt b) { return (conj(a)*b).real(); }
double cross(pt a, pt b) { return (conj(a)*b).imag(); }
pt project(pt a, pt b) { return b*dot(a,b)/norm(b); }

bool between(pt p, pt a, pt b) {
  return cmp(a.real(), b.real()) == 0 ?
    p.imag() >= min(a.imag(), b.imag()) and p.imag() <= max(a.imag(), b.imag()) :
    p.real() >= min(a.real(), b.real()) and p.real() <= max(a.real(), b.real());
}

double dist_pt_seg(pt p, pt a, pt b) {
  pt pp = a + project(p-a, a-b);
  if (between(pp, a, b)) return abs(p-pp);
  return min(abs(p-a), abs(p-b));
}

int n, l, h, x, y;
pt p[N][2];

int main() {
  while (~scanf("%d%d%d", &n, &l, &h)) {
    for (int i = 0; i < n; ++i) {
      x = i%2?l:0;
      scanf("%d", &y);
      p[i][0] = pt(x, y);
      scanf("%d%d", &x, &y);
      p[i][1] = pt(x, y);
    }

    double m = 1e18;
    for (int i = 1; i < n; ++i) {
      m = min(m, dist_pt_seg(p[i-1][1], p[i][0], p[i][1]));
      m = min(m, fabs(p[i-1][1].real()-(i%2?l:0)));
    }
    m = min(m, fabs(p[n-1][1].real()-((n-1)%2?0:l)));

    printf("%.2f\n", m);
  }

  return 0;
}
