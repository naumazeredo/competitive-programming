#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[222222];
vector<int> adj[222222];
int vis[222222];

int dfs(int u, int cats) {
  vis[u] = 1;
  if (c[u]) {
    cats++;
    if (cats > m)
      return 0;
  } else {
    cats = 0;
  }

  if (adj[u].size() == 1 && u != 1)
    return 1;

  int sum = 0;
  for (int i = 0; i < (int)adj[u].size(); ++i) {
    if (!vis[adj[u][i]])
      sum += dfs(adj[u][i], cats);
  }

  return sum;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> c[i];
  for (int i = 0; i < n-1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  memset(vis, 0, sizeof(vis));

  cout << dfs(1, 0) << endl;
  return 0;
}
