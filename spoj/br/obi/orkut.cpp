#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

char nomes[50][50];
set<int> adj[50];
vector<int> adjInv[50];
bool visited[50];
map<string, int> ids;

int main()
{
  char buffer[50];
  int n, m;
  int teste = 1;
  while (scanf("%d", &n) != EOF && n)
  {
    memset(visited, 0, 50 * sizeof(bool));

    for (int i = 0; i < n; ++i)
    {
      scanf("%s", nomes[i]);
      ids[nomes[i]] = i;
      adj[i].clear();
    }

    for (int i = 0; i < n; ++i)
    {
      scanf("%s %d", buffer, &m);
      int id = ids[buffer];
      for (int j = 0; j < m; ++j)
      {
        scanf("%s", buffer);
        int e = ids[buffer];
        adj[id].insert(e);
        adjInv[e].push_back(id);
      }
    }


    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
      if (visited[i])
        continue;

      if (adj[i].size() == 0)
      {
        visited[i] = true;
        for (int j = 0; j < adjInv[i].size(); ++j)
          adj[adjInv[i][j]].erase(i);

        res.push_back(i);
        i = -1;
        continue;
      }
    }

    printf("Teste %d\n", teste++);
    if (res.size() == n)
      for (int i = 0; i < n; ++i)
        printf("%s ", nomes[res[i]]);
    else
      printf("impossivel");
    printf("\n\n");
  }

  return 0;
}
