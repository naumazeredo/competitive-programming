#include <cstdio>
#include <queue>
#include <set>
#include <utility>
#include <functional>
using namespace std;

int parent[2222];
int custo[2222];
int rankset[2222];

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
    custo[pa] += custo[pb] + c;
  }
  else
  {
    parent[pa] = pb;
    custo[pb] += custo[pa] + c;
    if (rankset[pa] == rankset[pb])
      rankset[pb]++;
  }
}

int main()
{
  int n, m;
  int u, v, c;
  int teste = 1;
  while (scanf("%d %d", &n, &m) != EOF)
  {
    if (teste > 1)
      printf("\n");

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

    set<int> forest;
    for (int i = 1; i <= n; ++i)
      forest.insert(find(i));

    int mincusto = 0;
    for (set<int>::iterator it = forest.begin();
         it != forest.end();
         ++it)
      mincusto += custo[*it];

    printf("Instancia %d\n%d\n", teste++, mincusto);
  }

  return 0;
}
