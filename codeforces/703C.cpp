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
const int N = 1e4+5;

int n, w, v, u, x[N], y[N];

int main() {
  scanf("%d%d%d%d", &n, &w, &v, &u);
  for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);

  int m = 0;
  for (int i = 1; i < n; ++i) m = (y[i]==y[m] ? (x[i]<x[m]?i:m) : (y[i]<y[m]?i:m));

  int ok = 1;
  while (1) {
    if (1ll*y[m]*v > 1ll*x[m]*u) { ok = 0; break; }
    int nm = (n+m-1)%n;
    if (y[nm] <= y[m]) break;
    m = nm;
  }

  if (ok) return 0*printf("%.9f\n", w/(double)u);

  m = 0;
  for (int i = 1; i < n; ++i) m = (y[i]==y[m] ? (x[i]>x[m]?i:m) : (y[i]<y[m]?i:m));

  ld t = 0;
  int h = 0;
  while (1) {
    t += max(x[m]/(ld)v - t, (y[m]-h)/(ld)u);
    h = y[m];
    int nm = (m+1)%n;
    if (x[nm]<=x[m]) { t += (w-h)/(ld)u; break; }
    m = nm;
  }

  printf("%.9f\n", (double)t);

  return 0;
}
