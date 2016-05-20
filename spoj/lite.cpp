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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int n, m, op, s, e, st[4*N], lz[4*N];

void lazy(int p, int l, int r) {
  if (lz[p]) {
    st[p] = r-l+1-st[p];

    lz[p]=0;
    lz[2*p]=!lz[2*p];
    lz[2*p+1]=!lz[2*p+1];
  }
}

int query(int p, int l, int r, int i, int j) {
  lazy(p, l, r);
  if (r < i or l > j) return 0;
  if (l >= i and r <= j) return st[p];
  return query(2*p, l, (l+r)/2, i, j) + query(2*p+1, (l+r)/2+1, r, i, j);
}

void update(int p, int l, int r, int i, int j) {
  lazy(p, l, r);
  if (r < i or l > j) return;
  if (l >= i and r <= j) {
    lz[p]=1;
    lazy(p, l, r);
    return;
  }

  update(2*p, l, (l+r)/2, i, j);
  update(2*p+1, (l+r)/2+1, r, i, j);
  st[p] = st[2*p] + st[2*p+1];
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &op, &s, &e);
    if (op) printf("%d\n", query(1, 1, n, s, e));
    else update(1, 1, n, s, e);
  }
  return 0;
}
