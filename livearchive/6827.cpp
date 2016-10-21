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
const int N = 5e5+5;

vi adj[N];
int n, x[N], y[N], p[N], c[N], g[2], ans;
vector<pii> s[N];

void dfs(int u) {
  for (auto v : adj[u]) if (c[v]<0)
    c[v] = 1-c[u], g[c[v]]++, dfs(v);
}

int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < N; ++i) s[i].clear(), adj[i].clear();
    cl(c,-1);

    for (int i = 0; i < n; ++i)
      scanf("%d%d", &x[i], &y[i]), s[x[i]].pb({ y[i], i }), p[i]=i;
    sort(p, p+n, [](int a, int b){ return x[a] < x[b]; });

    for (int i = 1; i < N; ++i) sort(s[i].begin(), s[i].end());

    for (int i = 0; i < n; ++i) {
      int px = x[p[i]], py = y[p[i]];
      for (int j = -5; j <= 5; ++j) {
        int d = sqrt(5*5 - j*j);
        if (px+j<0 or px+j>=N) continue;
        auto it = lower_bound(s[px+j].begin(), s[px+j].end(), mp(py-d-1, 0),
                              [](pii a, pii b){ return a.st < b.st; });
        for (; it != s[px+j].end() and it->st <  py-d; it++) ;
        for (; it != s[px+j].end() and it->st <= py+d; it++) adj[p[i]].pb(it->nd);
      }
    }

    ans = 0;
    for (int i = 0; i < n; ++i) if (c[i]<0) {
      c[i] = 1; g[1] = 1; g[0] = 0;
      dfs(i);
      ans += min(g[0], g[1]);
    }

    printf("%d\n", ans);
  }
  return 0;
}
