#include <cstdio>

int parent[222222];
int rank[222222];
int guildpoints[222222];
int points[222222];

int find(int a)
{
  return (parent[a] == a ? a : parent[a] = find(parent[a]));
}

void unionSet(int a, int b)
{
  int p1 = find(a),
      p2 = find(b);

  if (p1 == p2)
    return;

  if (rank[p1] > rank[p2])
  {
    parent[p2] = p1;
    guildpoints[p1] += guildpoints[p2];
  }
  else
  {
    parent[p1] = p2;
    guildpoints[p2] += guildpoints[p1];
    if (rank[p1] == rank[p2])
      rank[p1]++;
  }
}

int main()
{
  int n, m, q, a, b;
  while (scanf("%d %d", &n, &m) != EOF && n)
  {
    int win = 0;

    for (int i = 1; i <= n; ++i)
    {
      scanf("%d", &points[i]);
      parent[i] = i;
      rank[i] = 1;
      guildpoints[i] = points[i];
    }

    for (int i = 0; i < m; ++i)
    {
      scanf("%d %d %d", &q, &a, &b);
      if (q == 1)
        unionSet(a, b);
      else
      {
        int pa = find(a),
            pb = find(b);
        int p1 = guildpoints[pa],
            p2 = guildpoints[pb];
        if ((find(1) == pa && p1 > p2) ||
            (find(1) == pb && p2 > p1))
          win++;
      }
    }

    printf("%d\n", win);
  }

  return 0;
}
