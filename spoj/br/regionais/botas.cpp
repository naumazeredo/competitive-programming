#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>


int main()
{
  int n;

  while (scanf("%d", &n) != EOF)
  {
    int total = 0;
    int botas[31][2];

    memset(botas, 0, sizeof(botas));

    for (int i = 0; i < n; ++i)
    {
      int m;
      char l;
      scanf("%d %c", &m, &l);

      if (l == 'E')
        botas[m - 30][0]++;
      else
        botas[m - 30][1]++;
    }

    for (int i = 0; i < 31; ++i)
      total += std::min(botas[i][0], botas[i][1]);

    printf("%d\n", total);
  }

  return 0;
}
