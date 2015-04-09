#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int n;
char names[100][100];
bool elim[100];

int nv;
int vote[2000][100];

int cnt[100];

char buffer[100];

int main()
{
  int t;
  scanf("%d", &t);

  for (int aa = 0; aa < t; ++aa)
  {
    if (aa != 0)
      printf("\n");

    memset(elim, 0, sizeof(elim));

    scanf("%d ", &n);
    for (int i = 1; i <= n; ++i)
      fgets(names[i], sizeof(names[i]), stdin);

    int v = 0;
    while (fgets(buffer, sizeof(buffer), stdin) && buffer[0] != '\n')
    {
      char* pch = strtok(buffer, " ");
      for (int i = 1; i <= n; ++i)
      {
        sscanf(pch, "%d", &vote[v][i]);
        pch = strtok(0, " ");
      }

      v++;
    }
    nv = v;

    while (1)
    {
      memset(cnt, 0, sizeof(cnt));

      for (int i = 0; i < nv; ++i)
      {
        for (int j = 1; j <= n; ++j)
        {
          if (!elim[vote[i][j]])
          {
            cnt[vote[i][j]]++;
            break;
          }
        }
      }

      int me = 1e9, ma = -1;
      for (int i = 1; i <= n; ++i)
      {
        if (!elim[i] && cnt[i] > ma)
          ma = cnt[i];
        if (!elim[i] && cnt[i] < me)
          me = cnt[i];
      }

      // All win
      if (me == ma)
      {
        for (int i = 1; i <= n; ++i)
          if (!elim[i])
            printf("%s", names[i]);
        break;
      }

      // >50%
      if (ma > nv / 2)
      {
        for (int i = 1; i <= n; ++i)
          if (!elim[i] && cnt[i] == ma)
            printf("%s", names[i]);
        break;
      }

      for (int i = 1; i <= n; ++i)
        if (!elim[i] && cnt[i] == me)
          elim[i] = true;
    }
  }

  return 0;
}
