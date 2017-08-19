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
const int N = 1e6+5;

int n, m, nh, p, q, v[N], st[4*N], h[4*N];

void build(int p, int l, int r) {
  if (l == r) {
    st[p] = v[l];
    //db(p _ l _ r _ h[p] _ st[p]);
    return;
  }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  h[p] = 1-h[2*p];
  st[p] = h[p] ? st[2*p]|st[2*p+1] : st[2*p]^st[2*p+1];
  //db(p _ l _ r _ h[p] _ st[p]);
}

void update(int p, int l, int r, int x, int v) {
  if (l == r and l == x) { st[p] = v; return; }
  if (l > x or r < x) return;
  update(2*p, l, (l+r)/2, x, v);
  update(2*p+1, (l+r)/2+1, r, x, v);
  st[p] = h[p] ? st[2*p]|st[2*p+1] : st[2*p]^st[2*p+1];
}

int main() {
  scanf("%d%d", &n, &m);
  nh = n;
  n = (1<<n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  build(1, 0, n-1);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &p, &q);
    update(1, 0, n-1, p-1, q);
    printf("%d\n", st[1]);
  }
  return 0;
}
