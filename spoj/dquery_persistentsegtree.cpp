/*
  @subject: persistent segment tree
*/
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
const int N = 1e5+5, M = 1e7+5;

int n, q, a, x, y, l[M], r[N];
int rcnt;
int lc[M], rc[M], st[M];

int update(int p, int l, int r, int i, int v) {
  int rt = ++rcnt;
  if (l == r) { st[rt] = v; return rt; }

  int mid = (l+r)/2;
  if (i <= mid) lc[rt] = update(lc[p], l, mid, i, v), rc[rt] = rc[p];
  else          rc[rt] = update(rc[p], mid+1, r, i, v), lc[rt] = lc[p];
  st[rt] = st[lc[rt]] + st[rc[rt]];

  return rt;
}

int query(int p, int l, int r, int i, int j) {
  if (l > j or r < i) return 0;
  if (i <= l and r <= j) return st[p];

  return query(lc[p], l, (l+r)/2, i, j)+query(rc[p], (l+r)/2+1, r, i, j);
}

int main() {
  scanf("%d", &n);
  cl(l, -1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a);

    if (l[a] == -1) r[i] = update(r[i-1], 1, n, i, 1);
    else {
      r[i] = update(r[i-1], 1, n, l[a], 0);
      r[i] = update(r[i], 1, n, i, 1);
    }
    l[a] = i;
  }

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &x, &y);
    printf("%d\n", query(r[y], 1, n, x, y));
  }

  return 0;
}
