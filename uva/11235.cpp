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

int n, q, x, y, a[N], e[N], d[N];
int st[4*N]; // 0: left, 1: best, 2: right

void build(int p, int l, int r) {
  if (l == r) {
    st[p] = 1;
    return;
  }

  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);

  st[p] = max(st[2*p], st[2*p+1]);
  st[p] = max(st[p], min(r-l+1, d[l]));
  st[p] = max(st[p], min(r-l+1, e[r]));

  int m = (l+r)/2;
  if (a[m] == a[m+1])
    st[p] = max(st[p], min(m-l+1, e[m]) + min(r-m, d[m+1]));
}

int query(int p, int l, int r, int i, int j) {
  if (i > r or j < l) return -1;
  if (i <= l and j >= r) return st[p];

  int q0 = query(2*p, l, (l+r)/2, i, j);
  int q1 = query(2*p+1, (l+r)/2+1, r, i, j);

  int ml = max(l, i), mr = min(r, j);

  int res = max(q0, q1);
  res = max(res, min(mr-ml+1, d[ml]));
  res = max(res, min(mr-ml+1, e[mr]));

  int m = (l+r)/2;
  if (a[m] == a[m+1])
    res= max(res, min(m-ml+1, e[m]) + min(mr-m, d[m+1]));

  return res;
}

int main() {
  while (~scanf("%d%d", &n, &q) and n) {
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) e[i] = a[i]==a[i-1]?e[i-1]+1:1;
    for (int i = n; i > 0; --i)  d[i] = a[i]==a[i+1]?d[i+1]+1:1;

    build(1, 1, n);

    for (int i = 0; i < q; ++i) {
      scanf("%d%d", &x, &y);
      printf("%d\n", query(1, 1, n, x, y));
    }
  }
  return 0;
}
