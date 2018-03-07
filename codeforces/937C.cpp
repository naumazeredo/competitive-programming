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

const ld EPS = 1e-12, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll k, d, t;

int main() {
  scanf("%lld%lld%lld", &k, &d, &t);
  if (k%d == 0) return printf("%lld\n", t), 0;

  ld n = (k+d-1)/d*d;
  ld t2 = (n-k)/2.0l;
  ld t1 = k;

  ll cyc = t/(t1+t2)+EPS;
  ld tc = cyc*(t1+t2);
  if (tc + t1 > t+EPS) return printf("%.12Lf\n", cyc*n + (t-tc)), 0;
  return printf("%.12Lf\n", cyc*n+t1+(t-tc-t1)*2), 0;

  return 0;
}
