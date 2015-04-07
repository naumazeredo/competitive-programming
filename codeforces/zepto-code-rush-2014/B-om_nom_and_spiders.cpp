#include <cstdio>
#include <cstring>

int cnt[2000];

int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  memset(cnt, 0, sizeof(cnt));

  char c;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      scanf(" %c", &c);
      if      (c == 'U')
      {
        if (i % 2 == 0)
          cnt[j]++;
      }
      else if (c == 'R')
      {
        if (j + i < m)
          cnt[j + i]++;
      }
      else if (c == 'L')
      {
        if (j - i >= 0)
          cnt[j - i]++;
      }
    }
  }

  for (int i = 0; i < m; ++i)
  {
    printf("%d", cnt[i]);
    if (i < m - 1)
      printf(" ");
  }
  printf("\n");

  return 0;
}
