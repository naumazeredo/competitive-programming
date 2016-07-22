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
const int N = 1e5+5, SQ = 320;

int n, m, k, a[N], l[N], r[N], p[N], pre[N], c[1<<20];
ll res, ans[N];

void add(int v) {
  res += c[v^k];
  c[v]++;
}

void rem(int v) {
  c[v]--;
  res -= c[v^k];
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pre[i] = (pre[i-1]^a[i]);
  for (int i = 0; i < m; ++i) scanf("%d%d", &l[i], &r[i]), l[i]--, r[i]++, p[i] = i;
  sort(p, p+m, [](int a, int b){ return l[a]/SQ == l[b]/SQ ? r[a] < r[b] : l[a] < l[b]; });

  int cl = 0, cr = 0;
  for (int i = 0; i < m; ++i) {
    int cur = p[i];
    while (cr < r[cur]) add(pre[cr++]);
    while (cl < l[cur]) rem(pre[cl++]);

    while (cr > r[cur]) rem(pre[--cr]);
    while (cl > l[cur]) add(pre[--cl]);

    ans[cur] = res;
  }

  for (int i = 0; i < m; ++i) printf("%lld\n", ans[i]);

  return 0;
}
