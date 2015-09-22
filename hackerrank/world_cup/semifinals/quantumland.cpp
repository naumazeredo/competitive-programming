#include <bits/stdc++.h>
using namespace std;

typedef pair<int, double> pfi;
pfi adj[200000];
int vis[200000];
int cy[200000];
double p;

int n;

void dfs(int u) {
  vis[u] = 1;
  int v = adj[u].first;
  if (!vis[v])
    dfs(v);
  else if (!cy[v]) {
    double acc = adj[v].second;
    for (int ne = adj[v].first; ne != v; ne = adj[ne].first) {
      acc *= adj[ne].second;
    }
    p += acc;
  }
  cy[u] = 1;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    adj[i] = make_pair(a, b / 100.0);
  }

  p = 0;
  memset(vis, 0, sizeof(vis));
  memset(cy, 0, sizeof(cy));
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) dfs(i);
  }

  printf("%.2f\n", p);
  return 0;
}
