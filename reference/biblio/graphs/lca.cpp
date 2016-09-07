// Lowest Common Ancestor
// Sparse table <O(nlogn), O(logn)>
int par[N][25], h[N];

// build
par[1][0] = 1;
for (int i = 0; (1<<i)<=n; ++i) for (int j = 1; j <= n; ++j)
  par[j][i] = par[par[j][i-1]][i-1];

// query
int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = 20; i >= 0; --i) if (h[v]+(1<<i)<=h[u]) u = par[u][i];
  if (u == v) return u;
  for (int i = 20; i >= 0; --i) if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
  return par[u][0];
}
