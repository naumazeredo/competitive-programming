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
const int N = 1e5+5, M = 2e5+5, SQ = 200;

int n, q, a[N], x[M], y[M], p[M], ans[M];
int u, c[1000005];

void add(int b) {
  c[a[b]]++;
  if (c[a[b]] == 1) u++;
}

void rem(int b) {
  c[a[b]]--;
  if (c[a[b]] == 0) u--;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &q);

  for (int i = 0; i < q; ++i) scanf("%d%d", &x[i], &y[i]), p[i] = i;
  sort(p, p+q, [](int a, int b) { return x[a]/SQ == x[b]/SQ ? y[a] < y[b] : x[a] < x[b]; });

  int l = 0, r = 0;
  for (int i = 0; i < q; ++i) {
    int cur = p[i];
    while (l < x[cur]) rem(l++);
    while (l > x[cur]) add(--l);
    while (r < y[cur]) add(++r);
    while (r > y[cur]) rem(r--);
    ans[cur] = u;
  }

  for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);

  return 0;
}
