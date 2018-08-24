// @subject: 
// @diff: 

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

struct point {
  ld x, y, z;
  point() { x = y = z = 0.0; }
  point(ld _x, ld _y, ld _z) : x(_x), y(_y), z(_z) {}
  ld norm() {
    return sqrt(x*x + y*y + z*z);
  }
  point operator +(point other) const{
    return point(x + other.x, y + other.y, z + other.z);
  }
  point operator -(point other) const{
    return point(x - other.x, y - other.y, z - other.z);
  }
};

point cross(point p1, point p2) {
  point ans;
  ans.x = p1.y*p2.z - p1.z*p2.y;
  ans.y = p1.z*p2.x - p1.x*p2.z;
  ans.z = p1.x*p2.y - p1.y*p2.x;
  return ans;
}

int n;
double x, y, z;
point p[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf%lf%lf", &x, &y, &z), p[i].x = x, p[i].y = y, p[i].z = z;

  point ans = cross(p[n-1], p[0]-p[n-1]);
  for (int i = 0; i < n-1; i++) ans = ans+cross(p[i], p[i+1]-p[i]);
  printf("%.12Lf\n", ans.norm()/2);

  return 0;
}
