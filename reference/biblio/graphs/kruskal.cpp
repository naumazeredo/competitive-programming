// Kruskal - MST O(ElogE)
vector<piii> edges;
// + Union-find

sort(edges.begin(), edges.end());
for (auto e : edges)
  unite(e.nd.st, e.nd.nd);
