#include <cstdio>

int main()
{
  int n;
  scanf("%d", &n);

  int m, v, s, a;
  for (int i = 0; i < n; ++i)
  {
    scanf("%d x %d", &m, &v);
    s = m - v;
    a = v;

    scanf("%d x %d", &m, &v);
    s += v - m;
    a -= v;

    if (s > 0)
      printf("Time 1\n");
    else if (s < 0)
      printf("Time 2\n");
    else if (a < 0)
      printf("Time 1\n");
    else if (a > 0)
      printf("Time 2\n");
    else
      printf("Penaltis\n");
  }

  return 0;
}
