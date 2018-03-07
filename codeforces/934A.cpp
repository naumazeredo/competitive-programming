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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e2+5;

int n, m;
ll a[N], b[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < m; i++) scanf("%lld", &b[i]);

  ll ans = LINF;
  for (int k = 0; k < n; k++) {
    ll tmp = -LINF;
    for (int i = 0; i < n; i++) if (i != k)
      for (int j = 0; j < m; j++)
        tmp = max(tmp, a[i]*b[j]);
    ans = min(ans, tmp);
  }

  printf("%lld\n", ans);

  return 0;
}
