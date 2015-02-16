#include <cstdio>
#include <cstring>

int main()
{
  int p, n, c;
  while (scanf("%d%d%d", &p, &n, &c) && p)
  {
    int total = 0;
    int proc[1000];
    memset(proc, 0, 1000 * sizeof(int));

    for (int i = 0; i < n; ++i)
    {
      int newproc[1000];
      for (int j = 0; j < p; ++j)
        scanf("%d", &newproc[j]);

      for (int j = 0; j < p; ++j)
      {
        if (newproc[j] == 0)
        {
          if (proc[j] >= c)
            total++;
          proc[j] = 0;
        }
        else
        {
          proc[j]++;
          if (i == n - 1 && proc[j] >= c)
            total++;
        }
      }
    }

    printf("%d\n", total);
  }

  return 0;
}
