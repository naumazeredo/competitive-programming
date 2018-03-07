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
const int N = 4e5+5;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, t, v=1;
ll last, p, q;

ll anc[N][25], sum[N][25], mx[N][25], val[N];

int main() {
  for (int i = 0; i < 25; i++) {
    mx[0][i] = mx[1][i] = LINF;
    sum[0][i] = sum[1][i] = LINF;
  }
  mx[1][0] = 0;
  sum[1][0] = 0;

  val[0] = LINF;
  val[1] = 0;

  scanf("%d", &n);
  while (n--) {
    scanf("%d%lld%lld", &t, &p, &q);
    ll r = p ^ last;
    if (t == 1) {
      ll w = q ^ last;

      v++;
      val[v] = w;

      int u = r;
      for (int i = 24; i >= 0; i--)
        if (mx[u][i] < w) u = anc[u][i];

      if (u and val[u] < w) u = anc[u][0];
      anc[v][0] = u;
      mx [v][0] = w;
      sum[v][0] = w;

      for (int i = 1; i<25; i++) {
        anc[v][i] = anc[anc[v][i-1]][i-1];
        mx[v][i]  = max(mx[v][i-1], mx[anc[v][i-1]][i-1]);
        sum[v][i] = min(sum[v][i-1] + sum[anc[v][i-1]][i-1], LINF);
      }
    } else {
      ll x = q ^ last;

      int ans = 0;

      if (val[r] <= x) {
        //x -= val[r];
        //ans++;

        for (int i = 24; i >= 0; i--) if (sum[r][i] <= x) {
          x -= sum[r][i];
          r = anc[r][i];
          ans += (1<<i);
        }
      }

      printf("%d\n", ans);
      last = ans;
    }
  }
  return 0;
}
