#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
pii magias[2222];
bool hasmagia[2222];
int costmagia[2222];
int mtot;

map<int, int> cache;
int custo_kill(int hp)
{
  if (hp <= 0)
    return 0;

  if (cache.find(hp) != cache.end())
    return cache[hp];

  int minmana = 1e9;
  for (int i = 0; i < mtot; ++i)
    minmana = min(minmana, magias[i].second + custo_kill(hp - magias[i].first));

  return cache[hp] = minmana;
}

vector<int> adj[2222];
int custo[2222];
bool visited[2222];
int dist[2222];

int dijkstra(int dest)
{
  queue<int> q;
  q.push(1);
  visited[1] = true;
  dist[1] = custo[1];

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (unsigned int i = 0; i < adj[u].size(); ++i)
    {
      int n = adj[u][i];
      if (!visited[n] || dist[u] + custo[n] < dist[n])
        dist[n] = dist[u] + custo[n];

      if (!visited[n])
      {
        q.push(n);
        visited[n] = true;
      }
    }
  }

  if (!visited[dest])
    return -1;

  return dist[dest];
}

int main()
{
  int m, n, g, k;
  while (scanf("%d%d%d%d", &m, &n, &g, &k) != EOF && m)
  {
    memset(hasmagia, 0, 2222 * sizeof(bool));
    memset(visited, 0, 2222 * sizeof(bool));
    mtot = 0;
    cache.clear();
    for (int i = 1; i <= n; ++i)
    {
      adj[i].clear();
      custo[i] = 0;
    }

    // ----
    int a, b;
    for (int i = 0; i < m; ++i)
    {
      scanf("%d%d", &a, &b);
      if (!hasmagia[b] || costmagia[b] > a)
      {
        magias[mtot++] = make_pair(b, a);
        hasmagia[b] = true;
        costmagia[b] = a;
      }
    }

    for (int i = 0; i < g; ++i)
    {
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for (int i = 0; i < k; ++i)
    {
      scanf("%d%d", &a, &b);
      custo[a] += custo_kill(b);
    }

    printf("%d\n", dijkstra(n));
  }

  return 0;
}

