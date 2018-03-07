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
const int N = 2e3+5;

int n, k, a[N];

ll fexp(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b&1) r = (r*a)%MOD;
    a = (a*a)%MOD;
    b /= 2;
  }
  return r;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  if (k == 0) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
  }

  for (int i = 0; i < n; i++) {
    ll val = 0;

    ll nn = k;
    ll pp = 1;
    ll bin = 1;

    for (int j = i; j >= 0; j--) {
      val = (val + (bin * a[j])%MOD)%MOD;

      // update bin
      bin = (bin * nn) % MOD;
      bin = (bin * fexp(pp, MOD-2)) % MOD;
      nn++, pp++;
    }
    printf("%lld ", val);
  }
  printf("\n");

  return 0;
}
