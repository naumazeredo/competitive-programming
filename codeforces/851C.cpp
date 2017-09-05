#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

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

struct point { int v[5]; };

int n, a[N][5], ba[N];

ll dot(point a, point b) {
  ll dot = 0;
  for (int k = 0; k < 5; k++) dot += a.v[k]*b.v[k];
  return dot;
}

ld sq(point a) { return sqrt(dot(a, a)); }

int ac(int i, int j, int k) {
  point x, y;
  for (int l = 0; l < 5; l++) {
    x.v[l] = a[j][l] - a[i][l];
    y.v[l] = a[k][l] - a[i][l];
  }
  return dot(x, y)/(sq(x)*sq(y)) > 0;
}

void solv(int i, int j, int k) {
  if (ac(i, j, k)) ba[i] = 1;
  else { ba[j] = ba[k] = 1; return; }

  if (ac(j, i, k)) ba[j] = 1;
  else { ba[k] = 1; return; }

  if (ac(k, i, j)) ba[k] = 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++) if (!ba[i])
    for (int j = 0; j < n; j++) if (i != j)
      for (int k = 0; k < n; k++) if (i != k and j != k)
        solv(i, j, k);

  vi ans;
  for (int i = 0; i < n; i++) if (!ba[i]) ans.pb(i+1);
  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d\n", x);
  return 0;
}
