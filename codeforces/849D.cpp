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

int n, w, h, g[N], p[N], t[N], x[N], y[N], ans[N];
set<int> sum;
map<int, vector<pii>> m[2];

int main() {
  scanf("%d%d%d", &n, &w, &h);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &g[i], &p[i], &t[i]), g[i]--;
    if (g[i]) y[i] = p[i], x[i] = -t[i];
    else x[i] = p[i], y[i] = -t[i];
    sum.insert(x[i]+y[i]);
    m[g[i]][x[i]+y[i]].push_back({p[i], i});
  }

  for (auto s : sum) {
    auto v0 = m[0][s];
    auto v1 = m[1][s];
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());

    vi a, b;
    for (int i = 0; i < v0.size(); i++)    a.pb(v0[i].nd);
    for (int i = v1.size()-1; i >= 0; i--) a.pb(v1[i].nd);

    for (int i = v1.size()-1; i >= 0; i--) b.pb(v1[i].nd);
    for (int i = 0; i < v0.size(); i++)    b.pb(v0[i].nd);

    for (int i = 0; i < a.size(); i++) ans[b[i]] = a[i];
  }

  for (int i = 0; i < n; i++)
    printf("%d %d\n", g[ans[i]]?w:x[ans[i]], g[ans[i]]?y[ans[i]]:h);

  return 0;
}
