#include <cstdio>

int main()
{
  int n;
  int r;
  while (scanf("%d", &n) != EOF && n)
  {
    int m = 0,
        j = 0;
    for (int i = 0; i < n; ++i)
    {
      scanf("%d", &r);
      if (r == 0) m++;
      else        j++;
    }

    printf("Mary won %d times and John won %d times\n", m, j);
  }

  return 0;
}
