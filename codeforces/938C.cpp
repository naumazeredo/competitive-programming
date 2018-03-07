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

int t, x;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &x);

    if (x == 0) {
      printf("1 1\n");
      continue;
    }
    if (x == 1) {
      printf("-1\n");
      continue;
    }

    int ok = 0;
    for (ll i = 1; i*i <= x; i++) if (x%i==0) {
      ll a = i;
      ll b = x/i;
      if ((a+b)%2) continue;
      ll n = (a+b)/2;
      ll k = (b-a)/2;
      ll m = n/k;
      if (n*n - (n/m)*(n/m) != x) continue;
      printf("%lld %lld\n", n, m);
      ok = 1;
      break;
    }

    if (!ok) printf("-1\n");
  }
  return 0;
}
