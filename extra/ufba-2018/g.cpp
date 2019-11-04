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
const int N = 1e5+5;

struct pt {
  int x, y;
  pt(int x=0, int y=0) : x(x), y(y) {}
  ld dist() { return sqrt(1ll*x*x + 1ll*y*y); }
};

int n, x, d;
ld a, t;

int main() {
  scanf("%d%d", &n, &x);
  scanf("%Lf%Lf%d", &a, &t, &d);
  a *= PI/180.0;

  ld time_per_rad = t/(2*PI);
  db(a _ time_per_rad);

  for (int i = 0; i < n; i++) {
    pt p;
    scanf("%d%d", &p.x, &p.y);

    if (p.dist() > d+EPS) {
      printf("0.000000\n");
      continue;
    }

    ld ans = 0;
    ld dir = atan2(p.y, p.x);
    if (dir < 0) dir += 2*PI;

    ld curt = 0;

    if (dir > 2*PI-a/2) dir -= 2*PI-a/2;
    else dir += a/2;

    //db(dir * time_per_rad _ x);

    if (dir*time_per_rad > x) {
      ld end = x/time_per_rad + a;
      if (end > dir) {
        if (dir > a) ans += end-dir;
        else ans += end;
      }
    } else {
      if (dir > a) ans += a;
      else ans += dir;
      //db(ans);

      curt += dir*time_per_rad;
      ll rev = (x-curt)/t;
      //db(rev);
      ans += rev*a;
      curt += rev*t;
      //db(ans*time_per_rad _ curt);

      assert(x+EPS > curt);

      ld end = (x-curt)/time_per_rad + a;
      //db(end);
      if (end > 2*PI) ans += end-2*PI;
    }

    printf("%.12Lf\n", ans*time_per_rad);
  }
  return 0;
}
