#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case " << tt << ": ";

    int n, m;
    int adj[200];
    int value[200];
    memset(adj, 0, sizeof(adj));

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
      cin >> value[i];

    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      if (adj[u] <= 0 || value[adj[u]] < value[v])
        adj[u] = v;
    }

    int sum = 0;
    int pos = 0;
    while (adj[pos] != 0) {
      pos = adj[pos];
      sum += value[pos];
    }

    cout << sum << " " << pos << endl;
  }

  return 0;
}
