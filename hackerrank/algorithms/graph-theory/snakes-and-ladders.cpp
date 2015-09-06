#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b;
vector<int> adj[200];
int vis[200];

int bfs() {
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < (int)adj[u].size(); ++i) {
      int v = adj[u][i];
      if (!vis[v]) {
        q.push(v);
        vis[v] = (abs(v-u) > 6 ? 0 : 1) + vis[u];
        if (v == 100)
          return vis[v];
      }
    }
  }

  return -1;
}

int main() {
  cin >> t;
  while (t--) {
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i < 100; ++i) {
      adj[i].clear();
      for (int j = 1; j <= 6; ++j)
        if (i + j <= 100)
          adj[i].push_back(i + j);
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      adj[a].clear();
      adj[a].push_back(b);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      adj[a].clear();
      adj[a].push_back(b);
    }

    cout << bfs() << endl;

    /*
    for (int i = 1; i <= 100; ++i) {
      cout << i << "(" << vis[i] << "): ";
      for (int j = 0; j < (int)adj[i].size(); ++j)
        cout << adj[i][j] << " ";
      cout << endl;
    }
    */
  }

  return 0;
}
