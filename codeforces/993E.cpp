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

const ld PI = acos(-1.);
const int N = 5e6+5;

// Fast Fourier Transform - O(nlogn)

/*
// Use struct instead. Performance will be way better!
typedef complex<ld> T;
T a[N], b[N];
*/

struct T {
  ld x, y;
  T() : x(0), y(0) {}
  T(ld a, ld b=0) : x(a), y(b) {}

  T operator/=(ld k) { x/=k; y/=k; return (*this); }
  T operator*(T a) const { return T(x*a.x - y*a.y, x*a.y + y*a.x); }
  T operator+(T a) const { return T(x+a.x, y+a.y); }
  T operator-(T a) const { return T(x-a.x, y-a.y); }
} a[N], b[N];

void fft(T* a, int n, int s) {
  for (int i=0, j=0; i<n; i++) {
    if (i>j) swap(a[i], a[j]);
    for (int l=n/2; (j^=l) < l; l>>=1);
  }

  for(int i = 1; (1<<i) <= n; i++){
    int M = 1 << i;
    int K = M >> 1;
    T wn = T(cos(s*2*PI/M), sin(s*2*PI/M));
    for(int j = 0; j < n; j += M) {
      T w = T(1, 0);
      for(int l = j; l < K + j; ++l){
        T t = w*a[l + K];
        a[l + K] = a[l]-t;
        a[l] = a[l] + t;
        w = wn*w;
      }
    }
  }
}

// assert n is a power of two greater of equal product size
// n = na + nb; while (n&(n-1)) n++;
void multiply(T* a, T* b, int n) {
  fft(a,n,1);
  fft(b,n,1);
  for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
  fft(a,n,-1);
  for (int i = 0; i < n; i++) a[i] /= n;
}

// Convert to integers after multiplying:
// (int)(a[i].x + 0.5);

int n, x, v[N], y;

int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; i++) scanf("%d", &y), v[i] = y < x;
  for (int i = 1; i < n; i++) v[i] += v[i-1];

  const int P = v[n-1]+5;
  assert(P < N);

  a[0].x = 1;
  b[P].x = 1;
  for (int i = 0; i < n; i++) {
    a[v[i]].x++;
    b[P-v[i]].x++;
  }

  /*
  db(P);
  for (int i = 0; i <= P; i++) db(i _ a[i].x _ b[i].x);
  */

  int s = 2*P;
  while (s&(s-1)) s += s&-s;
  multiply(a, b, s);

  ll ans0 = 0;
  ll cnt = 1+(v[0]==0);
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i-1]) cnt++;
    else {
      ans0 += cnt*(cnt-1)/2;
      cnt = 1;
    }
  }
  ans0 += cnt*(cnt-1)/2;

  printf("%lld ", ans0);
  for (int i = 1; i <= n; i++) printf("%lld ", (ll)(a[i+P].x + 0.5));
  printf("\n");

  return 0;
}
