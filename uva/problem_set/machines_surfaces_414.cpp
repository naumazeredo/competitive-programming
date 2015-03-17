#include <cstdio>

int main()
{
  int n, r, m, d;
  while (scanf("%d", &n) && n)
  {
    r = 0;
    m = 1000;
    char c;
    for (int i = 0; i < n; ++i)
    {
      d = 0;
      for (int j = 0; j < 25; ++j)
      {
        scanf("%c", &c);
        if (c == ' ')
        {
          d++;
          r++;
        }
      }
      getchar();

      if (m > d)
        m = d;
    }

    r -= m * n;

    printf("%d\n", r);
  }

  return 0;
}
