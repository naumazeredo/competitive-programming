// @subject: FFT
// @diff: 2

#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long double ld;
typedef long long ll;

const ld PI = acos(-1.);
const int N = 5e6+5;

// Fast Fourier Transform - O(nlogn)
struct T {
  double x, y;
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

int n;
vector<int> v;
vector<ll> p;

void solv_small() {
  set<ll> ans;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      ans.insert(p[j] - p[i-1]);
  printf("%d\n", (int)(ans.size()-1));
}

void solv_medium() {
  vector<bool> h(2e7+5);

  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      h[p[j] - p[i-1]]=1;

  int ans = 0;
  for (int i = 0; i < N; i++) ans += h[i];
  printf("%d\n", ans -1);
}

void solv_large() {
  const int S = p[n]+1;
  for (int i = 0; i <= n; i++) a[p[i]].x = 1, b[S-p[i]].x = 1;

  int sz = 2*S;
  while (sz&(sz-1)) sz += sz&-sz;

  multiply(a, b, sz);

  ll ans = 0;
  for (int i = S+1; i < sz; i++) ans += !!(ll)(a[i].x + 0.5);
  printf("%lld\n", ans-1);
}

int main() {
  scanf("%d", &n);
  v.resize(n+1); p.resize(n+1);

  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) p[i] = p[i-1] + v[i];

  if (n < 2e3) solv_small();
  else if (n < 2e4) solv_medium();
  else solv_large();

  return 0;
}
