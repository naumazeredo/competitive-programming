#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, e, c;

ll gcd(ll a, ll b) { return b?gcd(b, a%b):a; }

ll fastexp(ll p, ll q, ll m) {
  ll r = 1;
  while (q) {
    if (q&1) r = (r*p)%m;
    p = (p*p)%m;
    q >>= 1;
  }
  return r;
}

int x, y, d;
void exteuclid(int a, int b) {
  if (!b) { x=1, y=0, d=a; return; }
  exteuclid(b, a%b);
  int x1 = y, y1 = x - (a/b)*y;
  x = x1, y = y1;
}

int modinv(int a, int m) {
  exteuclid(a, m);
  return (x%m + m) % m;
}

int main() {
  scanf("%d%d%d", &n, &e, &c);
  int phi;
  for (int i = 3; i*i <= n; i+=2) if (n%i == 0) { phi = (i-1)*(n/i-1); break; }

  int d = modinv(e, phi);
  printf("%lld\n", fastexp(c, d, n));

  return 0;
}
