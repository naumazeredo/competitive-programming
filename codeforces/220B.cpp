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
const int N = 1e5+5, SQ = 400;

struct query {
  int l, r, id;
} q[N];

bool operator<(query a, query b) { return a.l/SQ == b.l/SQ ? a.r < b.r : a.l < b.l; }

int n, m, a[N], b[N], c[N], tot, ans[N];
vi v;

void add(int v, int o) {
  if (c[v] == o) tot--;
  c[v]++;
  if (c[v] == o) tot++;
}

void rem(int v, int o) {
  if (c[v] == o) tot--;
  c[v]--;
  if (c[v] == o) tot++;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), v.pb(a[i]);

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++)
    b[i] = lower_bound(v.begin(), v.end(), a[i])-v.begin();

  for (int i = 0; i < m; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].l--, q[i].r--, q[i].id = i;
  sort(q, q+m);

  int l = 0, r = -1;
  for (int i = 0; i < m; i++) {
    while (r < q[i].r) r++, add(b[r], a[r]);
    while (r > q[i].r) rem(b[r], a[r]), r--;
    while (l < q[i].l) rem(b[l], a[l]), l++;
    while (l > q[i].l) l--, add(b[l], a[l]);

    ans[q[i].id] = tot;
  }

  for (int i = 0; i < m; i++) printf("%d\n", ans[i]);

  return 0;
}
