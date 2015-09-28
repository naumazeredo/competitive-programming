#include <bits/stdc++.h>
using namespace std;

int n;
typedef pair<int, int> ii;
ii a[2000];
int adj[2000][2];
int dadj[2000][2];
int vis[2000];
int sx, sy;

int sqrdist(int u, int v) {
  int dx = a[u].first  - a[v].first,
      dy = a[u].second - a[v].second;
  return (dx * dx + dy * dy);
}

void dfs(int u) {
  vis[u]=1;
  for (int i = 0; i < 2; ++i)
    if (adj[u][i] && !vis[adj[u][i]])
      dfs(adj[u][i]);
}

int main() {
  while ((cin >> n) && n != 0) {
    memset(vis, 0, sizeof(vis));
    memset(adj, 0, sizeof(adj));
    memset(dadj, 0, sizeof(dadj));

    cin >> sx >> sy;
    a[1] = make_pair(sx, sy);
    for (int i = 2; i <= n; ++i) {
      int x, y;
      cin >> x >> y;
      a[i] = make_pair(x,y);
    }

    sort(a+1, a+n+1, [](ii x, ii y) { return x.second < y.second; });
    sort(a+1, a+n+1, [](ii x, ii y) { return x.first  < y.first; });

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        int s = sqrdist(i,j);
        if (!adj[i][0] || s <= dadj[i][0]) {
          adj[i][1]  = adj[i][0];
          dadj[i][1] = dadj[i][0];
          adj[i][0]  = j;
          dadj[i][0] = s;
        } else if (!adj[i][1] || s <= dadj[i][1]) {
          adj[i][1]  = j;
          dadj[i][1] = s;
        }
      }
    }

    int s;
    for (s = 1; a[s].first != sx || a[s].second != sy; s++);

    dfs(s);

    if (count(vis+1, vis+n+1, 1) != n)
      cout << "There are stations that are unreachable." << endl;
    else
      cout << "All stations are reachable." << endl;
  }

  return 0;
}
