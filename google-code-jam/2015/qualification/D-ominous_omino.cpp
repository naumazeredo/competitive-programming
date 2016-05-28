#include <cstdio>

int main()
{
  bool win;
  int t, x, r, c;
  scanf ("%d", &t);

  for (int i = 1; i <= t; ++i)
  {
    printf("Case #%d: ", i);
    scanf("%d%d%d", &x, &r, &c);

    win = false;
    if ((r * c) % x != 0)
      win = false;
    else if (x == 1)
      win = true;
    else if (x == 2)
    {
      if ((r * c) % 2 == 0)
        win = true;
    }
    else if (x == 3)
    {
      if ((r % 3 == 0 && c >= 2) ||
          (c % 3 == 0 && r >= 2))
        win = true;
    }
    else if (x == 4)
    {
      if (r >= 3 && c >= 3)
        win = true;
    }
    else if (x == 5)
    {
      if ((r >= 3 && c >= 3) &&
          !(r == 3 && c == 5) &&
          !(r == 5 && c == 3))
        win = true;
    }
    else if (x == 6)
    {
      if (r > 3 && c > 3)
        win = true;
    }

    if (win)
      printf("GABRIEL\n");
    else
      printf("RICHARD\n");
  }

  return 0;
}
