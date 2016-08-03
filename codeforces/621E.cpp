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
const int N = 1e2+5;

int n, b, k, x, a[50005];
ll m[N][N], t[N][N], r[N][N];

void mult(ll a[N][N], ll b[N][N], ll c[N][N]) {
  for (int i = 0; i < x; ++i) for (int j = 0; j < x; ++j) {
    c[i][j] = 0;
    for (int k = 0; k < x; ++k)
      c[i][j] += (a[i][k]*b[k][j])%MOD;
    c[i][j] = c[i][j]%MOD;
  }
}

void cp(ll a[N][N], ll b[N][N]) {
  for (int i = 0; i < x; ++i) for (int j = 0; j < x; ++j)
    b[i][j] = a[i][j];
}

void fastexp(ll b) {
  for (int i = 0; i < x; ++i) for (int j = 0; j < x; ++j) r[i][j] = i==j;
  while (b) {
    if (b&1) mult(r, m, t), cp(t, r);
    mult(m, m, t), cp(t, m);
    b>>=1;
  }

  cp(r, m);
}

int main() {
  scanf("%d%d%d%d", &n, &b, &k, &x);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  for (int i = 0; i < x; ++i) for (int j = 0; j < n; ++j) m[i][(10*i+a[j])%x]++;

  for (int i = 0; i < x; ++i) for (int j = 0; j < x; ++j) r[i][j] = i==j;
  while (b) {
    if (b&1) mult(r, m, t), cp(t, r);
    mult(m, m, t), cp(t, m);
    b>>=1;
  }

  cp(r, m);

  printf("%lld\n", r[0][k]);

  return 0;
}
