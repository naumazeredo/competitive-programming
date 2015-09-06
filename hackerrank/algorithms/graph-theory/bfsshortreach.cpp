#include <bits/stdc++.h>
using namespace std;

int t, n, m, s, a, b;
vector<int> adj[2000];
int vis[2000];

void bfs() {
  queue<int> q;
  q.push(s);
  vis[s] = 0;
  while(!q.empty()) {
    int v = q.front(); q.pop();
    for (int i = 0; i < (int)adj[v].size(); ++i) {
      if (vis[adj[v][i]] == -1) {
        q.push(adj[v][i]);
        vis[adj[v][i]] = vis[v] + 6;
      }
    }
  }
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;

    memset(vis, -1, sizeof(vis));
    for (int i = 1; i <= n; ++i)
      adj[i].clear();

    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    cin >> s;

    bfs();

    for (int i = 1; i <= n; ++i) {
      if (i != s)
        cout << vis[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
