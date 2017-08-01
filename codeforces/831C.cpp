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
const int N = 2e3+5, M = 2e7+5, D = 8e7;

int n, k, a[N], b[N], p[N];
multiset<int> x;
set<int> ans, e;

int main() {
  scanf("%d%d", &k, &n);
  for (int i = 0; i < k; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]), e.insert(b[i]);

  p[0] = a[0]; x.insert(p[0]);
  for (int i = 1; i < k; i++) p[i] = a[i]+p[i-1], x.insert(p[i]);

  int i = 0, j;
  for (auto ix = x.begin(); ix != x.end() and i <= k-n; ix++, i++) {
    j = 0;
    int v = (*e.begin()) - (*ix);
    int ok = 1;
    for (auto w : e) if (!x.count(w - v)) { ok = 0; break; }
    if (ok) ans.insert(v);
  }

  printf("%d\n", (int)ans.size());

  return 0;
}
