#include <cstdio>
#include <algorithm>

int main()
{
  int n, l;
  int v[100001];

  while (scanf("%d %d", &n, &l) && n)
  {
    int min_gaps = 1 << 29; // Number greater than 1.000.000.000

    if (n != 0)
    {
      for (int i = 0; i < l; ++i)
        scanf("%d", &v[i]);

      for (int i = 0; min_gaps && i < l; ++i)
      {
        int gaps = 0;

        for (int j = i + 1; j < l; ++j)
        {
          gaps += v[j] - v[j - 1] - 1;

          if (gaps + j - i + 1 >= n)
          {
            int a;
            if (v[j] - v[i] < n) a = j - i + 1;
            else a = j - i;
            gaps = n - a;
            min_gaps = std::min(min_gaps, gaps);
            break;
          }
        }
      }
    }

    if (min_gaps >= n)
      printf("%d\n", n - 1);
    else
      printf("%d\n", min_gaps);
  }

  return 0;
}
