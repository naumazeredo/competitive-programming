// Kuhn - Bipartite Matching O(VE)
int vis[N], b[n], ans;

int match(int u) {
  if (vis[u]) return 0;
  vis[u] = 1;
  for (int v : adj[u]) if (!b[v] or match(b[v])) {
    b[v]=u; return 1;
  }
  return 0;
}

for (int i = 1; i <= n; ++i) ans+=match(i);
