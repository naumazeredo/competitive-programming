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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7+5;

ll n, r, l[N], t[N], sz;

int main() {
  scanf("%lld%lld", &n, &r);
  for (int i = 0; i < n; ++i) scanf("%lld", &l[i]);
  for (int i = 0; i < n; ++i) scanf("%lld", &t[i]);

  for (int i = 0; i < n; ++i) if (t[i] < l[i]) return 0*printf("-1\n");

  vector<ll> ans;
  ll p = 0, rl = 0;
  for (int i = 0; i < n; ++i) {
    if (rl > l[i]) {
      p += l[i];
      rl = max(rl-l[i], 0ll);
      continue;
    }

    ll tt = 2*l[i] - rl;
    if (tt <= t[i]) {
      p += tt;
      rl = max(rl-tt, 0ll);
    } else {
      ll dest = p + t[i];
      p += rl;
      ll x = t[i] - l[i];
      p += 2*x;

      sz += (dest - p + r-1)/r;

      for (int j = 0; j < (dest - p + r-1)/r and sz <= 100000; ++j)
        ans.pb(p + r*j);

      p += (dest - p + r-1)/r * r;
      rl = p-dest;
      p = dest;
    }
  }

  printf("%lld\n", sz);
  if (sz <= 100000) {
    for (auto v : ans) printf("%lld ", v);
    printf("\n");
  }

  return 0;
}
