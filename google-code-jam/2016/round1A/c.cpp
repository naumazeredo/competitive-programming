#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int t, tt, n;
int f[1111];
int res;

bitset<1111> cycles;
int par[1111];

int best[1111];
int dist[1111];

int vis[1111];
int depth[1111];

void dfs(int u, int d) {
  vis[u]++;
  depth[u] = d;
  if (vis[f[u]] == 0) dfs(f[u], d+1);
  else if (vis[f[u]] == 1) res = max(res, d-depth[f[u]]+1);
  vis[u]++;
}

int main() {
  scanf("%d", &t);
  while (tt++ < t) {
    cl(f);
    cl(par);
    cl(best);
    cl(dist);
    cl(vis);
    cl(depth);
    cycles.reset();
    res = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &f[i]);

    for (int i = 1; i <= n; ++i) if (i == f[f[i]]) cycles.set(i), dist[i]++, par[i]=i, best[i]++;

    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i, 1);

    if (cycles.count()) {
      for (int c = 0; c < n; ++c) {
        for (int i = 1; i <= n; ++i) {
          if (!dist[i] and dist[f[i]]) {
            dist[i] = dist[f[i]]+1;
            par[i] = par[f[i]];
            best[par[i]] = max(best[par[i]], dist[i]);
          }
        }
      }

      int tmp = 0;
      for (int i = 1; i <= n; ++i) if (cycles[i]) tmp += best[i];
      res = max(res, tmp);
    }

    printf("Case #%d: %d\n", tt, res);
  }
  return 0;
}
