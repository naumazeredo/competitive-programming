#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

const int INF = 2e9;
const int MAXN = 1e5+5;

int N, a, b, q, s, t;

vector<ii> adj[MAXN];
ll hs[MAXN];
int vis[MAXN];

int P[MAXN][20], T[MAXN], L[MAXN];
void process() {
  int i, j;
  for (i = 0; i < N; ++i) for (j = 0; (1<<j) < N; ++j)
    P[i][j] = -1;
  for (i = 0; i < N; ++i) P[i][0] = T[i];
  for (j = 1; (1<<j) < N; ++j) for (i = 0; i < N; ++i)
    if (P[i][j-1] != -1) P[i][j] = P[P[i][j-1]][j-1];
}

int query(int p, int q) {
  int lg, i;
  if (L[p] < L[q]) swap(p, q);

  for (lg = 1; (1 << lg) <= L[p]; ++lg); lg--;
  for (i = lg; i >= 0; --i)
    if (L[p] - (1<<i) >= L[q])
      p = P[p][i];

  if (p == q) return p;
  for (i = lg; i >= 0; --i)
    if (P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];
  return T[p];
}

int dfs(int u, ll h) {
  vis[u]=1;
  hs[u] = h;
  for (int i = 0; i < adj[u].size(); ++i)
    if (!vis[adj[u][i].first])
      dfs(adj[u][i].first, h+adj[u][i].second);
}

int main() {
  while (scanf("%d", &N) != EOF && N) {
    for (int i = 0; i < N; ++i)
      adj[i].clear();

    T[0] = -1;
    L[0] = 1;
    vis[0] = 0;
    for (int i = 1; i <= N-1; ++i) {
      scanf("%d%d", &a, &b);
      adj[a].push_back(ii(i, b));

      vis[i] = 0;
      L[i] = L[a]+1;
      T[i] = a;
    }

    process();
    dfs(0, 0);

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      scanf("%d%d", &s, &t);
      int lca = query(s, t);
      ll path = hs[s] + hs[t] - 2*hs[lca];
      if (i) printf(" ");
      printf("%lld", path);
    }
    printf("\n");
  }
  return 0;
}
