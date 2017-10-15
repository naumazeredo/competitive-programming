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
const int N = 1e6+5;

// Fast Fourier Transform - O(nlogn)

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

int t;
char x[N], y[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s%s", x, y);
    int nx = strlen(x), ny = strlen(y);

    for (int i = nx-1; i >= 0; i--) a[nx-1-i] = T(x[i]-'0', 0);
    for (int i = ny-1; i >= 0; i--) b[ny-1-i] = T(y[i]-'0', 0);

    int n = nx+ny;
    while (n&(n-1)) n++;

    for (int i = nx; i < n; i++) a[i] = T(0,0);
    for (int i = ny; i < n; i++) b[i] = T(0,0);

    multiply(a, b, n);
    int c = 0;
    vi ans;
    for (int i = 0; i < n; i++) {
      int v = (int)(a[i].x+0.5);
      ans.pb((v+c)%10); c = (v+c)/10;
    }
    if (c) ans.pb(c);

    while (ans.size() and !ans.back()) ans.pop_back();
    if (ans.empty()) ans.pb(0);
    while (ans.size()) printf("%d", ans.back()), ans.pop_back();
    puts("");
  }
  return 0;
}
