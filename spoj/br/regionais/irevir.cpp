#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

bool adj[2001][2001];
bool visited[2001];
bool visitedtrans[2001];

int dfs(int u)
{
  int cnt = 1;

  visited[u] = true;
  for (int i = 2; i <= 2000; ++i)
    if (adj[u][i] && !visited[i])
      cnt += dfs(i);

  return cnt;
}

int dfstrans(int u)
{
  int cnt = 1;

  visitedtrans[u] = true;
  for (int i = 2; i <= 2000; ++i)
    if (adj[i][u] && !visitedtrans[i])
      cnt += dfstrans(i);

  return cnt;
}

int main()
{
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF && n)
  {
    memset(adj, false, 2001 * 2001 * sizeof(bool));
    memset(visited, false, 2001 * sizeof(bool));
    memset(visitedtrans, false, 2001 * sizeof(bool));

    for (int i = 0; i < m; ++i)
    {
      int v, w, p;
      scanf("%d%d%d", &v, &w, &p);

      adj[v][w] = true;
      if (p == 2)
        adj[w][v] = true;
    }

    if (dfs(1) == n && dfstrans(1) == n)
      printf("1\n");
    else
      printf("0\n");
  }

  return 0;
}
