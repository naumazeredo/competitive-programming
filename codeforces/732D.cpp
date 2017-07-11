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

int n, m, d[N], a[N], l[N];

int solv(int x) {
  cl(l,0);
  for (int i = 1; i <= x; ++i) l[d[i]] = i;
  for (int i = 1; i <= m; ++i) if (!l[i]) return 0;
  int t = 0;
  for (int i = 1; i <= x; ++i) {
    if (d[i] and l[d[i]] == i) {
      t -= a[d[i]];
      if (t < 0) return 0;
    } else {
      t++;
    }
  }
  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
  for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);

  int lo = 1, hi = n;
  while (lo < hi) {
    int mid = (lo+hi)/2;
    if (solv(mid)) hi = mid;
    else lo = mid+1;
  }

  printf("%d\n", solv(lo)?lo:-1);

  return 0;
}
