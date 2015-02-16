#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int main()
{
  int n;

  while (scanf("%d", &n) && n)
  {
    int total = 0;
    int ps[1000];

    for (int i = 0; i < n; ++i)
      scanf("%d", &ps[i]);

    for (int i = 0; i < n; ++i)
    {
      total += ps[i];
      for (int j = i + 1; j < n; ++j)
      {
        if (ps[j] == ps[i])
          ps[j] = 1;
        else
          ps[j]++;
      }
    }

    printf("%d\n", total);
  }

  return 0;
}
