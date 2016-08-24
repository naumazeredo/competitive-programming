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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll n, a, b;

int test(ll p, ll q) {
  if ((p+q)%2==1) return 0;
  ll c = (p+q)/2, b = (p-q)/2;
  if (n*n + b*b == c*c and b and c) {
    printf("%lld %lld\n", abs(b), abs(c));
    return 1;
  }
  return 0;
}

int main() {
  scanf("%lld", &n);

  for (ll i = 1; i*i <= n; ++i) if (n%i==0) {
    ll x = n/i;

    if (test(i*i*x, x)) return 0;
    if (test(x, x*i*i)) return 0;
    if (test(x*x*i, i)) return 0;
    if (test(i, i*x*x)) return 0;
  }

  printf("-1\n");

  return 0;
}
