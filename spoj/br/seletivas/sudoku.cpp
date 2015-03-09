#include <cstdio>
#include <set>
using namespace std;

int mat[10][10];

int main()
{
  int n;
  scanf("%d", &n);

  int teste = 1;
  for (int i = 0; i < n; ++i)
  {
    for (int y = 0; y < 9; ++y)
      for (int x = 0; x < 9; ++x)
        scanf("%d", &mat[y][x]);

    bool ok = true;
    set<int> l;
    // Linhas
    for (int y = 0; y < 9 && ok; ++y)
    {
      l.clear();
      for (int x = 0; x < 9; ++x)
        l.insert(mat[y][x]);

      if (l.size() < 9)
        ok = false;
    }

    if (ok)
    {
      // Coluna
      for (int y = 0; y < 9 && ok; ++y)
      {
        l.clear();
        for (int x = 0; x < 9; ++x)
          l.insert(mat[x][y]);

        if (l.size() < 9)
          ok = false;
      }
    }

    if (ok)
    {
      // Quadrados
      for (int i = 0; i < 3 && ok; ++i)
      {
        for (int j = 0; j < 3 && ok; ++j)
        {
          l.clear();
          for (int y = 0; y < 3; ++y)
            for (int x = 0; x < 3; ++x)
              l.insert(mat[i * 3 + y][j * 3 + x]);

          if (l.size() < 9)
            ok = false;
        }
      }
    }

    printf("Instancia %d\n", teste++);
    if (ok)
      printf("SIM\n\n");
    else
      printf("NAO\n\n");
  }

  return 0;
}
