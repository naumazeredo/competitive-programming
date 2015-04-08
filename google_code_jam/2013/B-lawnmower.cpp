#include <cstdio>

int l[100][100];
int mx[100];
int my[100];

int main()
{
  int t;
  scanf("%d", &t);

  int n, m;
  for (int i = 1; i <= t; ++i)
  {
    printf("Case #%d: ", i);

    scanf("%d%d", &n, &m);
    for (int y = 0; y < n; ++y)
      for (int x = 0; x < m; ++x)
        scanf("%d", &l[y][x]);

    // Y
    for (int y = 0; y < n; ++y)
    {
      my[y] = l[y][0];
      for (int x = 1; x < m; ++x)
        if (l[y][x] > my[y])
          my[y] = l[y][x];
    }

    // X
    for (int x = 0; x < m; ++x)
    {
      mx[x] = l[0][x];
      for (int y = 1; y < n; ++y)
        if (l[y][x] > mx[x])
          mx[x] = l[y][x];
    }

    bool ok = true;
    for (int y = 0; y < n && ok; ++y)
    {
      for (int x = 0; x < m && ok; ++x)
      {
        if (l[y][x] < my[y])
          for (int k = 0; k < n && ok; ++k)
            if (l[k][x] > l[y][x])
              ok = false;

        if (l[y][x] < mx[x])
          for (int k = 0; k < m && ok; ++k)
            if (l[y][k] > l[y][x])
              ok = false;
      }
    }

    if (ok)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
