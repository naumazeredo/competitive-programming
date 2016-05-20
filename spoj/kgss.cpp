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

int n, q, v[N], st[4*N][2];

void build(int p, int l, int r) {
  if (l == r) {
    st[p][0] = v[l];
    return;
  }

  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);

  vi tmp;
  tmp.pb(st[2*p][0]), tmp.pb(st[2*p][1]);
  tmp.pb(st[2*p+1][0]), tmp.pb(st[2*p+1][1]);
  sort(tmp.begin(), tmp.end());

  st[p][0] = tmp[2];
  st[p][1] = tmp[3];
}

vi query(int p, int l, int r, int i, int j) {
  if (r < i or l > j) return vi();
  if (i <= l and r <= j) {
    vi t; t.pb(st[p][0]); t.pb(st[p][1]);
    return t;
  }

  vi ql = query(2*p, l, (l+r)/2, i, j);
  vi qr = query(2*p+1, (l+r)/2+1, r, i, j);
  vi tmp;
  tmp.insert(tmp.end(), ql.begin(), ql.end());
  tmp.insert(tmp.end(), qr.begin(), qr.end());
  sort(tmp.begin(), tmp.end());

  vi ans;
  ans.pb(tmp[tmp.size()-1]), ans.pb(tmp[tmp.size()-2]);

  return ans;
}

void update(int p, int l, int r, int a, int x) {
  if (l > a or r < a) return;
  if (l == r and l == a) { st[p][0] = x; return; }

  update(2*p, l, (l+r)/2, a, x);
  update(2*p+1, (l+r)/2+1, r, a, x);

  vi tmp;
  tmp.pb(st[2*p][0]), tmp.pb(st[2*p][1]);
  tmp.pb(st[2*p+1][0]), tmp.pb(st[2*p+1][1]);
  sort(tmp.begin(), tmp.end());

  st[p][0] = tmp[2];
  st[p][1] = tmp[3];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

  build(1, 0, n-1);

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    char c; int x, y;
    scanf(" %c%d%d", &c, &x, &y);
    if (c == 'U') update(1, 0, n-1, x-1, y);
    if (c == 'Q') {
      vi ans = query(1, 0, n-1, x-1, y-1);
      printf("%d\n", ans[0]+ans[1]);
    }
  }
  return 0;
}
