#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 100009
#define MAXM 10000009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x));
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
#define MAXS 2009

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	double norm() {
		return hypot(x, y);
	}
	point normalized() {
		return point(x,y)*(1.0/norm());
	}
	double angle() { return atan2(y, x); }
	double polarAngle() {
		double a = atan2(y, x);
		return a < 0 ? a + 2*acos(-1.0) : a;
	}
	bool operator < (point other) const {
		if (fabs(x - other.x) > EPS) return x < other.x;
		else return y < other.y;
	}
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
	point operator +(point other) const {
		return point(x + other.x, y + other.y);
	}
	point operator -(point other) const {
		return point(x - other.x, y - other.y);
	}
	point operator *(double k) const {
		return point(x*k, y*k);
	}
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double inner(point p1, point p2) {
	return p1.x*p2.x + p1.y*p2.y;
}

double cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}

point P[MAXN];
point c;
int n;
double ans = 1e+30;

point read() {
  point p;
  scanf("%lf %lf", &p.x, &p.y);
  return p;
}

void check(double t1, point a, point b) {
  double dt = dist(a, b);
  double t2 =t1 +dt;
  if (fabs(dist(b, c) - t2) < EPS) ans = min(ans, t2);
  if (fabs(dist(a, c) - t1) < EPS) ans = min(ans, t1);
  if (a == b) {
    if (fabs(dist(a, c) - t1) < EPS) {
      ans = min(ans, t1);
    }
    return;
  }
  if (dist(a, c) < t1 + EPS) return;
  if (dist(b, c) > t2 + EPS) return;
  double a1 = 2*inner(b-a, a-c)/dt - 2*t1;
  double a0 = inner(a-c, a-c) - t1*t1;
  if (fabs(a1) < EPS) return;
  double t = -a0/a1;
  if (t < -EPS || t > dt + EPS) return;
  //if (t < 0) t = 0;
  //if (t > dt) t = dt; 
  ans = min(ans, t+t1);
}

int main() {
  scanf("%d", &n);
  c = read();
  FOR(i, n) P[i] = read();
  double t = 0;
  FOR(i, n-1) {
    check(t, P[i], P[i+1]);
    t += dist(P[i], P[i+1]);
  }
  if (ans > 1e+29) printf("-1\n");
  else printf("%.20f\n", ans);
  return 0;
}