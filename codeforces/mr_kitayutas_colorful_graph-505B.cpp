#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[200][200];
int visited[200][200];

int dfs(int u, int v, int c)
{
  if (u == v) return 1;
  visited[c][u] = 1;
  for (int i = 0; i < adj[c][u].size(); ++i)
    if (!visited[c][adj[c][u][i]] && dfs(adj[c][u][i], v, c))
      return 1;
  return 0;
}

int main()
{
  memset(visited, 0, sizeof(visited));

  int n, m, a, b, c, q;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; ++i)
  {
    scanf("%d%d%d", &a, &b, &c);
    adj[c][a].push_back(b);
    adj[c][b].push_back(a);
  }

  scanf("%d", &q);
  for (int i = 0; i < q; ++i)
  {
    scanf("%d%d", &a, &b);
    c = 0;
    for (int j = 1; j <= m; ++j)
    {
      memset(visited, 0, sizeof(visited));
      if (dfs(a, b, j)) c++;
    }

    printf("%d\n", c);
  }

  return 0;
}
