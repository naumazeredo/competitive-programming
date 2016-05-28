#include <cstdio>

int main()
{
  int t, r, c, w;
  scanf("%d", &t);

  for (int tt = 1; tt <= t; tt++)
  {
    printf("Case #%d: ", tt);
    scanf("%d%d%d", &r, &c, &w);
    if (w == c)
      printf("%d\n", r + w-1);
    else if (c % w == 0)
      printf("%d\n", r * (c / w) + w - 1);
    else
      printf("%d\n", r * (c / w) + w);
  }

  return 0;
}
