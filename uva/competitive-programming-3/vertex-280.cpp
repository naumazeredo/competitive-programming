#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> adj[200];
int vis[200];

void dfs(int u) {
  for (int i = 0; i < (int)adj[u].size(); ++i) {
    if (!vis[adj[u][i]]) {
      vis[adj[u][i]] = 1;
      dfs(adj[u][i]);
    }
  }
}

int main() {
  int a, b;

  while (scanf("%d", &n) != EOF && n != 0) {
    for (int i = 1; i <= n; ++i)
      adj[i].clear();

    while (scanf("%d", &a) != EOF && a != 0)
      while (scanf("%d", &b) != EOF && b != 0)
        adj[a].push_back(b);

    scanf("%d", &a);
    for (int i = 0; i < a; ++i) {
      memset(vis, 0, sizeof(vis));

      scanf("%d", &b);
      dfs(b);

      vector<int> inac;

      for (int j = 1; j <= n; ++j)
        if (!vis[j]) inac.push_back(j);

      printf("%d", (int)inac.size());
      for (int j = 0; j < (int)inac.size(); ++j)
        printf(" %d", inac[j]);
      printf("\n");
    }
  }

  return 0;
}
