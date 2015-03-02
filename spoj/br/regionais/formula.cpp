#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int pos[100][100];
int sist[10][101];
int pont[100];

int main()
{
  int g, p, s;
  while (scanf("%d %d", &g, &p) != EOF && g)
  {
    for (int i = 0; i < g; ++i)
      for (int j = 0; j < p; ++j)
        scanf("%d", &pos[i][j]);

    memset(sist, 0, 10 * 100 * sizeof(int));

    scanf("%d", &s);
    for (int i = 0; i < s; ++i)
    {
      int k;
      scanf("%d", &k);
      for (int j = 1; j <= k; ++j)
        scanf("%d", &sist[i][j]);
    }

    for (int i = 0; i < s; ++i)
    {
      memset(pont, 0, 100 * sizeof(int));
      for (int j = 0; j < g; ++j)
        for (int k = 0; k < p; ++k)
          pont[k] += sist[i][pos[j][k]];

      int m = 0;
      vector<int> camp;
      for (int j = 0; j < p; ++j)
      {
        int t = pont[j];
        if (t > m)
        {
          m = t;
          camp.clear();
        }
        if (t == m)
          camp.push_back(j + 1);
      }

      printf("%d", camp[0]);
      for (int j = 1; j < (int)camp.size(); ++j)
        printf(" %d", camp[j]);
      printf("\n");
    }
  }

  return 0;
}
