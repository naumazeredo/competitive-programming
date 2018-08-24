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
const int N = 1e5+5;

ll n, m, k;

int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  if (k <= n-1) return printf("%lld %lld\n", 1ll+k, 1ll), 0;
  if (k <= n+m-2) return printf("%lld %lld\n", n, 1ll+(k-n+1)), 0;

  k -= n+m-1;
  ll y = k/(2*m-2);
  k -= y*(2*m-2);

  if (k < m-1) return printf("%lld %lld\n", n-2*y-1, m-k), 0;

  k -= m-1;
  printf("%lld %lld\n", n-2*y-2, 2+k);
  return 0;
}
