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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+5;

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int t, n, x, y, a[N];
ll g[2][N], l[2][N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (y%x != 0) { printf("-1\n"); continue; }
    if (x != y and n == 1) { printf("-1\n"); continue; }
    if (n == 1) { printf("%d\n", a[1] == x ? 0 : 1); continue; }

    set<int> v;
    for (int i = 1; i*i <= y; i++) if (y%i == 0) {
      if (i%x == 0) v.insert(i);
      if ((y/i)%x == 0) v.insert(y/i);
    }

    for (int i = 0; i <= n+1; i++) {
      g[0][i] = g[1][i] = 0;
      l[0][i] = l[1][i] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) if (!v.count(a[i])) ans++;

    for (int i = 1; i <= n; i++) if (v.count(a[i])) {
      g[0][i] = gcd(g[0][i-1], a[i]);
      l[0][i] = lcm(l[0][i-1], a[i]);
    }

    for (int i = n; i >= 1; i--) if (v.count(a[i])) {
      g[1][i] = gcd(g[1][i+1], a[i]);
      l[1][i] = lcm(l[1][i+1], a[i]);
    }

    if (ans < 2 and (g[0][n] != x or l[0][n] != y)) {
      ans = 2;
      if (ans == 1) {
        //db(1);
        for (int b : v)
          if (gcd(g[0][n], b) == x and lcm(l[0][n], b) == y)
            ans = 1;
      } else {
        //db(2);
        for (int i = 1; i <= n; i++)
          for (int b : v) {
            ll gg = gcd(g[0][i-1], g[1][i+1]);
            ll ll = lcm(l[0][i-1], l[1][i+1]);
            //db(i _ b _ gg _ ll _ gcd(gg, b) _ lcm(ll, b));
            if (gcd(gg, b) == x and lcm(ll, b) == y)
              ans = 1;//, db(1);
          }
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}
