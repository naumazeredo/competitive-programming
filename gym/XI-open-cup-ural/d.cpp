#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

#define f first
#define s second

const int INF = 2e9;

int n, m;
vector<iiii> adj[100005];
int p[100005];
int mt[100005];

int d, a, td, ta;
vector<int> route;

int dfs(int u, int t, int edge) {
  mt[u] = min(mt[u], t);
  if (u == a && mt[u] <= ta) { route.push_back(edge); return 1; }

  while (p[u] && adj[u][p[u]-1].f.f >= mt[u]) {
    p[u]--;
    iiii x = adj[u][p[u]];
    if (dfs(x.s.f, x.f.s, x.s.s)) { route.push_back(edge); return 1; }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &d, &a, &td, &ta);
    adj[d].push_back(iiii(ii(td, ta), ii(a, i)));
  }

  scanf("%d%d%d%d", &d, &a, &td, &ta);

  for (int i = 0; i < 100005; ++i) p[i] = adj[i].size(), mt[i] = INF;

  if (a == d && ta >= td) {
    printf("0\n");
    return 0;
  }

  if (dfs(d, td, 0)) {
    route.pop_back();
    reverse(route.begin(), route.end());
    printf("%zd\n", route.size());
    for (int i = 0; i < route.size(); ++i)
      printf("%d ", route[i]);
    printf("\n");
  } else printf("Impossible\n");

  return 0;
}
