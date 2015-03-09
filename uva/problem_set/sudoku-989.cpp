#include <cstdio>

int mat[10][10];
int n;

void printsudoku()
{
  for (int y = 0; y < n*n; ++y)
  {
    printf("%d", mat[y][0]);
    for (int x = 1; x < n*n; ++x)
      printf(" %d", mat[y][x]);
    printf("\n");
  }
}

bool place(int num, int x, int y)
{
  for (int i = 0; i < n * n; ++i)
    if (mat[y][i] == num && i != x)
      return false;

  for (int i = 0; i < n * n; ++i)
    if (mat[i][x] == num && i != y)
      return false;

  int py = (y/n)*n,
      px = (x/n)*n;
  for (int i = py; i < py+n; ++i)
    for (int j = px; j < px+n; ++j)
      if (mat[i][j] == num && (i != y || j != x))
        return false;

  return true;
}

bool sudoku(int p)
{
  int row = p/(n*n),
      col = p%(n*n);
  while (mat[row][col] != 0)
  {
    p++;
    row = p/(n*n);
    col = p%(n*n);
  }

  if (p >= n*n*n*n)
    return true;

  for (int i = 1; i <= n*n; ++i)
  {
    if (place(i, col, row))
    {
      mat[row][col] = i;

      if (p == n*n*n*n -1)
        return true;
      else
        if (sudoku(p+1))
          return true;
    }
    mat[row][col] = 0;
  }

  return false;
}

int main()
{
  bool print = false;
  while (scanf("%d", &n) != EOF)
  {
    if (print)
      printf("\n");
    else
      print = true;

    for (int i = 0; i < n*n; ++i)
      for (int j = 0; j < n*n; ++j)
        scanf("%d", &mat[i][j]);

    if (sudoku(0))
      printsudoku();
    else
      printf("NO SOLUTION\n");
  }

  return 0;
}
