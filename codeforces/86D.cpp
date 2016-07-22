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
const int N = 2e5+5, SQ = 500;

int n, q, a[N], l[N], r[N], p[N];
ll ans[N], c[1000005], s;

void add(int x) {
  int v = a[x];
  s -= c[v] * c[v] * v;
  c[v]++;
  s += c[v] * c[v] * v;
}

void rem(int x) {
  int v = a[x];
  s -= c[v] * c[v] * v;
  c[v]--;
  s += c[v] * c[v] * v;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < q; ++i) scanf("%d%d", &l[i], &r[i]), p[i] = i;
  sort(p, p+q, [](int a, int b){ return l[a]/SQ == l[b]/SQ ? r[a] < r[b] : l[a] < l[b]; });

  int cl = 0, cr = 0;
  for (int i = 0; i < q; ++i) {
    int cur = p[i];
    while (cl < l[cur]) rem(cl++);
    while (cl > l[cur]) add(--cl);

    while (cr < r[cur]) add(++cr);
    while (cr > r[cur]) rem(cr--);
    ans[cur] = s;
  }

  for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);

  return 0;
}
