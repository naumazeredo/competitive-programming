#include <cstdio>

int main()
{
  int n, x, y;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d", &x, &y);
    printf("%d cm2\n", (x * y) / 2);
  }

  return 0;
}
