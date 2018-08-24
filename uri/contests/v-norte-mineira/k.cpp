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

ll add(ll a, ll b) {
  a += b;
  if (a > MOD) a-=MOD;
  return a;
}

ll mul(ll a, ll b) { return a*b%MOD; }

struct mat {
  ll v[3][3];
  mat() {
    memset(v,0,sizeof(v));
    v[0][0] = v[1][1] = v[2][2] = 1;
  }

  mat& operator=(mat x) {
    memcpy(v, x.v, sizeof v);
    return *this;
  }
};

mat operator*(mat x, mat y) {
  mat res;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      res.v[i][j] = 0;
      for (int k = 0; k < 3; k++)
        res.v[i][j] = add(res.v[i][j], mul(x.v[i][k], y.v[k][j]));
    }
  }
  return res;
}

ll n;
mat m, a;

mat fexp(ll b) {
  mat res;
  a = m;

  while (b) {
    if (b&1) res = res*a;
    a = a*a;
    b >>= 1;
  }

  return res;
}

ll calc(ll x) {
  mat a = fexp(x);

  ll ans = 0;
  ans = add(ans, a.v[0][0]);
  ans = add(ans, a.v[0][1]);
  ans = add(ans, a.v[0][2]);

  return ans;
}

int main() {
  m.v[0][0] = 0;
  m.v[0][1] = 1;
  m.v[0][2] = 1;

  m.v[1][0] = 1;
  m.v[1][1] = 0;
  m.v[1][2] = 0;

  m.v[2][0] = 0;
  m.v[2][1] = 1;
  m.v[2][2] = 0;

  while (~scanf("%lld", &n)) {
    if (n == 1) { printf("1\n"); continue; }
    if (n == 2) { printf("2\n"); continue; }
    if (n == 3) { printf("2\n"); continue; }
    if (n == 4) { printf("3\n"); continue; }

    //for (int i = 4; i <= 100; i++) db(i _ calc(i-3));

    printf("%lld\n", add(calc(n-3), calc(n-4)));
  }
  return 0;
}
