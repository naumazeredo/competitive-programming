#include <cstdio>

int main()
{
  int t;
  scanf("%d", &t);

  double v, m, n, acc;
  double c, f, x;
  for (int i = 1; i <= t; ++i)
  {
    printf("Case #%d: ", i);

    scanf("%lf%lf%lf", &c, &f, &x);

    v = 2.0;
    acc = 0.0;
    m = x / v;
    n = m;
    while (n <= m)
    {
      m = n;
      acc += c / v;

      v += f;
      n = acc + x / v;
    }

    printf("%lf\n", m);
  }

  return 0;
}
