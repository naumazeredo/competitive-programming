// Articulation points and Bridges O(V+E)
int par[N], art[N], low[N], num[N], cnt;

void articulation(int u) {
  low[u] = num[u] = ++cnt;
  for (int v : adj[u]) {
    if (!num[v]) {
      par[v] = u;
      articulation(v);
      if (low[v] >= num[u]) art[u] = 1;
      if (low[v] >  num[u]) // u-v bridge
    } else if (v != par[u]) {
      low[u] = min(low[u], num[v]);
    }
  }
}

// root special case
art[root] &= adj[i].size()>1;
