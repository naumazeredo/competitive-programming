#include <cstdio>

char arena[100][100];
int x, y;
char d;

int main()
{
  int n, m, s;
  while (scanf("%d %d %d", &n, &m, &s) != EOF && n)
  {
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        char c;
        scanf(" %c", &c);
        arena[i][j] = c;
        if (c == 'N' || c == 'S' || c == 'O' || c == 'L')
        {
          x = j;
          y = i;
          d = c;
        }
      }
      getchar(); // ignore \n
    }

    int score = 0;
    for (int i = 0; i < s; ++i)
    {
      char c;
      scanf(" %c", &c);

      if (c == 'F')
      {
        if      (d == 'N' && y > 0     && arena[y-1][x] != '#') y--;
        else if (d == 'S' && y < n - 1 && arena[y+1][x] != '#') y++;
        else if (d == 'O' && x > 0     && arena[y][x-1] != '#') x--;
        else if (d == 'L' && x < m - 1 && arena[y][x+1] != '#') x++;
        if (arena[y][x] == '*')
        {
          score++;
          arena[y][x] = '.';
        }
      }
      else if (c == 'D')
      {
        if      (d == 'N') d = 'L';
        else if (d == 'L') d = 'S';
        else if (d == 'S') d = 'O';
        else if (d == 'O') d = 'N';
      }
      else if (c == 'E')
      {
        if      (d == 'N') d = 'O';
        else if (d == 'L') d = 'N';
        else if (d == 'S') d = 'L';
        else if (d == 'O') d = 'S';
      }
    }

    printf("%d\n", score);
  }

  return 0;
}
