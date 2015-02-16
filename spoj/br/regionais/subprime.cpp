#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

int main()
{
  int b, n;

  while (scanf("%d%d", &b, &n) && (b || n))
  {
    int rs[20];
    for (int i = 0; i < b; ++i)
      scanf("%d", &rs[i]);

    for (int i = 0; i < n; ++i)
    {
      int d, c, v;
      scanf("%d%d%d", &d, &c, &v);
      d--;
      c--;
      rs[c] += v;
      rs[d] -= v;
    }

    int i;
    for (i = 0; i < b; ++i)
    {
      if (rs[i] < 0)
      {
        printf("N\n");
        break;
      }
    }

    if (i >= b)
      printf("S\n");
  }

  return 0;
}
