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
const int N = 1e7+5;

int n, q, v[N], st[4*N][2], t, a, b;

void build(int p, int l, int r) {
  if (l == r) { st[p][0] = st[p][1] = v[l]; return; }
  build(2*p,l,(l+r)/2);
  build(2*p+1,(l+r)/2+1,r);
  st[p][0] = min(st[2*p][0], st[2*p+1][0]);
  st[p][1] = max(st[2*p][1], st[2*p+1][1]);
}

void update(int p, int l, int r, int x, int v) {
  if (l == r and l == x) { st[p][0] = st[p][1] = v; return; }
  if (x < l or x > r) return;
  update(2*p, l, (l+r)/2, x, v);
  update(2*p+1, (l+r)/2+1, r, x, v);
  st[p][0] = min(st[2*p][0], st[2*p+1][0]);
  st[p][1] = max(st[2*p][1], st[2*p+1][1]);
}

pii query(int p, int l, int r, int i, int j) {
  if (l > j or r < i) return {INF, -INF};
  if (i <= l and r <= j) return {st[p][0], st[p][1]};
  pii p0 = query(2*p, l, (l+r)/2, i, j);
  pii p1 = query(2*p+1, (l+r)/2+1, r, i, j);
  return {min(p0.st, p1.st), max(p0.nd, p1.nd)};
}

int main() {
  while (~scanf("%d", &n) and n) {
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    scanf("%d", &q);

    build(1, 0, n-1);
    while (q--) {
      scanf("%d%d%d", &t, &a, &b);
      if (t == 1) update(1, 0, n-1, a-1, b);
      else {
        pii x = query(1, 0, n-1, a-1, b-1);
        printf("%d\n", x.nd - x.st);
      }
    }
  }
  return 0;
}
