#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int main()
{
  int n;

  while (scanf("%d", &n) && n)
  {
    for (int i = 0; i < n; ++i)
    {
      int a, b, c, d, e;
      scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
      a = 1 - a / 128;
      b = 1 - b / 128;
      c = 1 - c / 128;
      d = 1 - d / 128;
      e = 1 - e / 128;

      //printf("a %d\nb %d\nc %d\nd %d\ne %d\n", a, b, c, d, e);

      if (a + b + c + d + e == 1)
      {
        if (a)
          printf("A\n");
        else if (b)
          printf("B\n");
        else if (c)
          printf("C\n");
        else if (d)
          printf("D\n");
        else if (e)
          printf("E\n");
      }
      else
        printf("*\n");
    }
  }

  return 0;
}
