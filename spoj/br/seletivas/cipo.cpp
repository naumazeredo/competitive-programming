#include <cstdio>
#include <queue>
#include <set>
#include <utility>
#include <functional>
using namespace std;

int parent[2222];
int custo[2222];
int rankset[2222];
int mincusto;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
priority_queue< pipii, vector<pipii>, greater<pipii> > edges;

// Kruskal

int find(int a)
{
  return (parent[a] == a) ? a : parent[a] = find(parent[a]);
}

void unionset(int a, int b, int c)
{
  int pa = find(a),
      pb = find(b);

  if (pa == pb)
    return;

  if (rankset[pa] > rankset[pb])
  {
    parent[pb] = pa;
  }
  else
  {
    parent[pa] = pb;
    if (rankset[pa] == rankset[pb])
      rankset[pb]++;
  }
  mincusto += c;
}

int main()
{
  int n, m;
  int u, v, c;
  int teste = 1;
  while (scanf("%d %d", &n, &m) != EOF)
  {
    mincusto = 0;

    for (int i = 1; i <= n; ++i)
    {
      parent[i] = i;
      rankset[i] = 1;
      custo[i] = 0;
    }

    for (int i = 0; i < m; ++i)
    {
      scanf("%d %d %d", &u, &v, &c);
      edges.push(make_pair(c, make_pair(u, v)));
    }

    while (!edges.empty())
    {
      pipii cur = edges.top();
      edges.pop();
      unionset(cur.second.first, cur.second.second, cur.first);
    }

    printf("Instancia %d\n%d\n\n", teste++, mincusto);
  }

  return 0;
}
