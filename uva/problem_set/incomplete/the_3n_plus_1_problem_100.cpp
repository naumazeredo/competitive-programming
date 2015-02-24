#include <cstdio>

int threenproblem(int n)
{
  int cnt = 1;
  while (n != 1)
  {
    if (n & 1)
      n = 3 * n + 1;
    else
      n /= 2;
    cnt++;
  }
  return cnt;
}

int main()
{
  int x, y;
  while (scanf("%d%d", &x, &y) != EOF)
  {
    int maxcnt = 0;
    for (int i = x; i <= y; ++i)
    {
      int cnt = threenproblem(i);
      if (cnt > maxcnt)
        maxcnt = cnt;
    }

    printf ("%d %d %d\n", x, y, maxcnt);
  }

  return 0;
}
