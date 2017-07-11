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
const int N = 1e7+5;

typedef complex<ld> T;
typedef vector<T> VT;

/*
const int mod = 479*(1<<21)+1;
const int root = 3;
const int root_1 = 334845270;
const int root_pw = 1<<21;
*/

const int mod = 7*(1<<20)+1;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1<<20;

int n, m;
ll dp[N], a[N];

ll fexp(ll a, ll b, ll m) {
  ll r = 1;
  for (; b; b>>=1, a=(a*a)%m) if (b&1) r = (r*a)%m;
  return r;
}

/*
// a: vector containing polynomial
// n: power of two greater or equal product size
void ntt(ll* a, int n, bool inv) {
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1)
      j -= bit;
    j += bit;
    if (i < j)
      swap(a[i], a[j]);
  }

  for (int k=2; k<=n; k<<=1) {
    ll len = inv ? root_1 : root;
    for (int i=k; i<root_pw; i<<=1) len *= len, len %= mod;

    for (int i=0; i<n; i+=k) {
      ll w = 1;
      for (int j=0; j<k/2; ++j) {
        ll u = a[i+j], v = a[i+j+k/2] * w % mod;
        a[i+j] = (u+v)%mod;
        a[i+j+k/2] = (u-v+mod)%mod;
        w = w*len % mod;
      }
    }
  }
  if (inv) {
    ll nrev = fexp(n, mod-2, mod);
    for (int i=0; i<n; ++i)
      a[i] = (a[i]*nrev) % mod;
  }
}

void multiply(ll* a, int n) {
  n*=2;
  while (n&(n-1)) n++;
  ntt(&a[0],n,0);
  for (int i = 0; i < n; ++i) a[i] = (a[i]*a[i])%mod;
  ntt(&a[0],n,1);
}
*/

void fft(T* a, int n, bool inv) {
  if (n == 1) return;
  T tmp[n];
  for (int i = 0; i < n/2; ++i)
    tmp[i] = a[2*i], tmp[i+n/2] = a[2*i+1];

  fft(&tmp[0], n/2, inv);
  fft(&tmp[n/2], n/2, inv);

  T wn = exp(T(0, (inv?-2:2)*M_PI/n)), w(1);
  for (int i = 0; i < n/2; ++i, w*=wn)
    a[i] = tmp[i] + w*tmp[i+n/2],
    a[i+n/2] = tmp[i] - w*tmp[i+n/2];
}

void multiply(VT& a, VT b) {
  int n = a.size() + b.size();
  while (n&(n-1)) ++n;
  a.resize(n); b.resize(n);

  fft(&a[0],n,0);
  fft(&b[0],n,0);
  for (int i = 0; i < n; ++i) a[i] *= b[i];

  fft(&a[0],n,1);
  for (int i = 0; i < n; ++i) a[i] /= n;
}


int main() {
  scanf("%d%d", &n, &m);
  VT b, c;
  for (int i = 1; i < m; i++) dp[fexp(i, n, m)]++;
  //for (int i = 0; i < m; i++) a[i] = dp[i];
  //multiply(a, m);
  for (int i = 0; i < m; i++) b.pb(dp[i]), c.pb(dp[i]);
  multiply(b, c);
  for (int i = 0; i < b.size(); i++) a[i] = (ll)(b[i].real()+0.5);

  ll ans = 0;
  for (int i = 0; i < 2*m; i++)
    ans += a[i]*dp[i%m];
  printf("%lld\n", ans);
  return 0;
}
