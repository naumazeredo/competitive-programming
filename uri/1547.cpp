#include <cstdio>
#define abs(x) (((x) > 0) ? (x) : -(x))

int main()
{
  int n, q, s, a;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d", &q, &s);
    int closest = -1, closeness = 1e9;
    for (int j = 1; j <= q; ++j)
    {
      scanf("%d", &a);
      if (closest < 0 || abs(s-a) < closeness)
      {
        closest = j;
        closeness = abs(s - a);
      }
    }

    printf("%d\n", closest);
  }

  return 0;
}
