#include <cstdio>

int main()
{
  int n;
  while (scanf("%d", &n) && n)
  {
    int sides = 0;

    for (int i = 0; i < n; ++i)
    {
      int c, v;
      scanf("%d%d", &c, &v);
      sides += v/2;
    }

    printf("%d\n", sides/2);
  }

  return 0;
}
