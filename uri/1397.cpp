#include <cstdio>

int main()
{
  int n, a, b;
  while (scanf("%d", &n) != EOF && n)
  {
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; ++i)
    {
      scanf("%d%d", &a, &b);
      if (a > b) p1++;
      else if (a < b) p2++;
    }

    printf("%d %d\n", p1, p2);
  }

  return 0;
}
