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
const int N = 2e6+5, SQ = 1005;

int n, m, a[N], b[N], l[N], r[N], last[N];
ll ans[N], pre[N];
vi v, q[N];

ll bit[N];

void add(int p, int v) {
  while (p <= N) bit[p]^=v, p+=p&-p;
}

ll query(int p) {
  ll sum = 0;
  while (p) sum^=bit[p], p-=p&-p;
  return sum;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pre[i]=pre[i-1]^a[i], v.pb(a[i]);

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= n; ++i)
    b[i] = lower_bound(v.begin(), v.end(), a[i])-v.begin()+1;

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) scanf("%d%d", &l[i], &r[i]), q[r[i]].pb(i);

  for (int i = 1; i <= n; ++i) {
    if (last[b[i]]) add(last[b[i]], a[i]);
    last[b[i]] = i;
    add(last[b[i]], a[i]);

    for (int j = 0; j < q[i].size(); ++j) {
      int k = q[i][j];
      ans[k] = query(r[k])^query(l[k]-1)^pre[r[k]]^pre[l[k]-1];
    }
  }

  for (int i = 0; i < m; ++i) printf("%lld\n", ans[i]);

  return 0;
}
