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
  #define db(x)
  #define dbs(x)
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

int x, y;

ll fexp(ll a, ll b) {
  ll r = 1;
  for (a %= MOD; b; b >>= 1, a = (a*a)%MOD)
    if (b&1) r = (r*a)%MOD;
  return r;
}

ll p2(ll x) { return fexp(2, x); }

ll summod(ll x, ll y) {
  x += y;
  if (x > MOD) x -= MOD;
  if (x < 0) x += MOD;
  return x;
}

ll addmod(ll x, ll y) {
  x += y;
  if (x > MOD) x -= MOD;
  return x;
}

ll mulmod(ll x, ll y) {
  return x*y % MOD;
}

int mobius(ll n) {
  int r = 1;
  for (int i = 2; i*i <= n; i++) if (n%i == 0) {
    r = -r;
    n /= i;
    if (n%i == 0) return 0;
  }
  if (n > 1) r = -r;
  return addmod(r, MOD);
}

int main() {
  scanf("%d%d", &x, &y);
  if (y%x) return printf("0\n"), 0;
  y /= x;

  vector<ll> d;
  int i;
  for (i = 1; i*i < y; i++) if (y%i==0)
    d.push_back(i), d.push_back(y/i);
  if (i*i == y) d.push_back(i);

  ll ans = 0;
  for (auto x : d) ans = summod(ans, mulmod(p2(x-1), mobius(y/x)));

  printf("%lld\n", ans);

  return 0;
}
