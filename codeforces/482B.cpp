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

int n, m, a[N], l[N], r[N], q[N];
int st[4*N], s[N][40];

void build(int p, int l, int r) {
  if (l == r) { st[p] = a[l]; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = st[2*p] & st[2*p+1];
}

int query(int p, int l, int r, int i, int j) {
  if (i > r or j < l) return 0xffffffff;
  if (i <= l and j >= r) return st[p];
  return query(2*p, l, (l+r)/2, i, j) & query(2*p+1, (l+r)/2+1, r, i, j);
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &l[i], &r[i], &q[i]);
    int x = q[i];
    for (int j = 0; j < 31; ++j) {
      s[l[i]][j] += !!(x&(1<<j));
      s[r[i]+1][j] -= !!(x&(1<<j));
    }
  }

  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 31; ++j)
      s[i][j] += s[i-1][j];

  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 31; ++j) if (s[i][j])
      a[i] |= (1<<j);

  build(1, 1, n);

  int ok = 1;
  for (int i = 0; i < m; ++i)
    if (query(1, 1, n, l[i], r[i]) != q[i])
      ok = 0;

  if (ok) {
    printf("YES\n");
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    printf("\n");
  } else printf("NO\n");

  return 0;
}
