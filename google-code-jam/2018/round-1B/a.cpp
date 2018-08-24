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
const int N = 2e5+5;

int t, n, l, c[N], x, extra, sum[N];

int go(int u) {
  if (~sum[u]) return sum[u];
  int r = 100*u%n;
  if (r == 0 or r >= (n+1)/2) sum[u] = 0;
  else sum[u] = 1 + go(u+1);
  return sum[u];
}

int calc(int v) {
  return 100*v/(ld)n + 0.5L;
}

int solv(int extra) {
  vector<int> v;

  for (int i = 0; i < l; i++) v.push_back(c[i]);
  sort(v.begin(), v.end(), [](int a, int b){ return go(a) < go(b); });

  int res = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    while (1+go(1) <= go(v[i]) and 1+go(1) <= extra) {
      int diff = 1+go(1);
      extra -= diff;

      res += calc(diff);
    }

    int diff = min(extra, go(v[i]));
    v[i] += diff;
    extra -= diff;

    res += calc(v[i]);
  }

  while (1+go(1) <= extra) {
    int diff = 1+go(1);
    extra -= diff;
    res += calc(diff);
  }

  res += calc(extra);

  return res;
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(c, 0, sizeof c);
    memset(sum, -1, sizeof sum);

    scanf("%d%d", &n, &l);

    extra = n;
    for (int i = 0; i < l; i++) {
      scanf("%d", &c[i]);
      extra -= c[i];
    }

    int ans = solv(extra);

    printf("Case #%d: ", tt);
    printf("%d\n", ans);
  }
  return 0;
}
