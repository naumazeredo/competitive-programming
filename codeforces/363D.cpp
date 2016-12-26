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

int n, m, a, b[N], p[N];

int main() {
  scanf("%d%d%d", &n, &m, &a);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &p[i]);
  sort(b,b+n);
  sort(p,p+m);

  int lo = 0, hi = min(n, m)+1;
  int t, ok;
  while (lo < hi) {
    int mid = (lo+hi)/2;
    if (mid > min(n,m)) { lo = hi; break; }

    t = a, ok = 1;
    for (int i = 0; i < mid; ++i) {
      t -= max(0, p[i]-b[n-mid+i]);
      if (t < 0) { ok = 0; break; }
    }

    if (ok) lo = mid+1;
    else hi = mid;
  }

  lo--;
  if (lo < 0) lo = 0;

  t = 0;
  for (int i = 0; i < lo; ++i) t += p[i];

  printf("%d %d\n", lo, max(0, t-a));

  return 0;
}
