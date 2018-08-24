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

const int MOD = 1e9+7;

ll x, k;

ll add(ll a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

ll sub(ll a, ll b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

ll mul(ll a, ll b) {
  return a*b%MOD;
}

ll fexp(ll a, ll b) {
  ll r = 1;
  for (a%=MOD; b; b >>= 1, a = mul(a,a)) if (b&1) r = mul(r,a);
  return r;
}

int main() {
  scanf("%lld%lld", &x, &k);
  if (x == 0) return !printf("0\n");
  if (k == 0) return !printf("%lld\n", 2*x%MOD);

  x %= MOD;

  ll ans = mul(fexp(2, 2*k), x);
  ans = sub(ans, sub(fexp(2, 2*k-1), fexp(2, k-1)));
  ans = mul(ans, fexp(fexp(2, k-1), MOD-2));

  printf("%lld\n", ans);

  return 0;
}
