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

int s, t, q, x, m, a, b, c, ans, mdist[N], dist[N], vis[N], par[N];
vi adj[N], adjw[N];

int dfs(int u) {
  vis[u] = 1;
  int ret = 0;
  for (int i = 0; i < (int)adj[u].size(); ++i) {
    int v = adj[u][i], w = adjw[u][i];
    if (v == par[u]) continue;
    if (!vis[v]) {
      par[v] = u;
      dist[v] = dist[u] + w;
      dfs(v);
    }

    if (vis[v] == 1 and w + dist[u] - dist[v] >= m)
      ans = min(ans, w + dist[u] - dist[v] + 2*mdist[v]);
  }
  vis[u] = 2;

  return ret;
}

int main() {
  while (~scanf("%d%d", &s, &t)) {
    for (int i = 1; i <= s; ++i) adj[i].clear(), adjw[i].clear();

    for (int i = 0; i < t; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      adj[a].pb(b), adjw[a].pb(c);
      adj[b].pb(a), adjw[b].pb(c);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      scanf("%d%d", &x, &m);

      cl(par,0); cl(dist,63); cl(mdist,63); cl(vis,0);
      ans = INF;

      priority_queue<pii> pq;
      pq.push({ 0, x });
      mdist[x] = 0;

      while (pq.size()) {
        int u = pq.top().nd, d = -pq.top().st; pq.pop();

        if (d > mdist[u]) continue;
        for (int j = 0; j < (int)adj[u].size(); ++j) {
          int v = adj[u][j], w = adjw[u][j];
          if (mdist[v] > mdist[u] + w)
            mdist[v] = mdist[u] + w,
            pq.push({ -mdist[v], v });
        }
      }

      dfs(x);

      printf("%d\n", ans==INF?-1:ans);
    }
  }

  return 0;
}
