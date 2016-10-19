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
const int N = 1e2+5;

int n, q, m, a, xt[N];
vi adj[N];
set<int> p[N];

int x, vis[N], b[N*N], ans;

bool match(int u) {
  if (vis[u]==x) return 0;
  vis[u] = x;
  for (int v : adj[u])
    if (!b[v] or match(b[v])) return b[v]=u;
  return 0;
}

int main() {
  while (~scanf("%d%d", &n, &q)) {
    for (int i = 1; i <= n; ++i) {
      p[i].clear();

      scanf("%d", &m);
      if (m<n) p[i].insert(0);
      for (int j = 0; j < m; ++j) scanf("%d", &a), p[i].insert(a);
    }

    for (int i = 0; i < q; ++i) {
      for (int j = 1; j <= n; ++j) adj[j].clear();
      cl(vis,0); cl(b,0); cl(xt,0), x=0;

      scanf("%d", &m);
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &a);
        for (int k = 1; k <= n; ++k) if (p[k].count(a)) {
          adj[k].pb(j);
          xt[k] = 1;
        }
      }

      if (m<n)
        for (int k = 1; k <= n; ++k)
          for (int j = m+1; j <= n; ++j)
            if (xt[k] or p[k].count(0))
              adj[k].pb(j);

      ans = 0;
      for (int j = 1; j <= n; ++j) x++, ans += match(j);
      printf("%c\n", ans==n?'Y':'N');
    }
  }
  return 0;
}
