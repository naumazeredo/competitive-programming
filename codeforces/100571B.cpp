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
const int N = 1e5+5;
ll mod(ll x) { return (MOD+x%MOD)%MOD; }

int n, q, a, b, x[N], l, r;
ll f[N], p[N];

int main() {
  scanf("%d%d%lld%lld%d%d", &n, &q, &f[0], &f[1], &a, &b);
  for (int i = 2; i <= n; ++i) f[i] = mod(mod(a*f[i-2])+mod(b*f[i-1]));
  for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &l, &r);
    if (l == r) {
      p[l] = mod(p[l]+f[0]);
      p[l+1] = mod(p[l+1]+mod(-b*f[0]));
      p[l+2] = mod(p[l+2]+mod(-a*f[0]));
      continue;
    }

    p[l] = mod(p[l]+f[0]);
    p[l+1] = mod(p[l+1]+f[1]);
    p[l+1] = mod(p[l+1]+mod(-b*f[0]));
    p[r+1] = mod(p[r+1]+mod(-b*f[r-l]));
    p[r+1] = mod(p[r+1]+mod(-a*f[r-l-1]));
    p[r+2] = mod(p[r+2]+mod(-a*f[r-l]));
  }

  for (int i = 2; i <= n; ++i) p[i] = mod(p[i] + mod(mod(a*p[i-2]) + mod(b*p[i-1])));

  for (int i = 1; i <= n; ++i) printf("%lld ", mod(x[i]+p[i]));
  printf("\n");
  return 0;
}
