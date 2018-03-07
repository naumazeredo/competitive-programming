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

ll n, m, k;

ll fastexp(ll a, ll b) {
  ll r = 1;
  for (a%=MOD; b; a = (a*a)%MOD, b>>=1) if (b&1) r = (r*a)%MOD;
  return r;
}

int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  if (k==-1 and (n+m)%2) printf("0\n");
  else printf("%lld\n", fastexp(fastexp(2, n-1), m-1));
  return 0;
}
