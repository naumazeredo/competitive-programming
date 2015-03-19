#include <cstdio>

int main()
{
  int n;
  char c;
  while (scanf("%d", &n) != EOF && n)
  {
    int d = 0;
    for (int i = 0; i < n; ++i)
    {
      scanf(" %c", &c);
      if (c == 'D') d++;
      else d--;
      d = (d + 4) % 4;
    }

    if (d == 0)      printf("N\n");
    else if (d == 1) printf("L\n");
    else if (d == 2) printf("S\n");
    else if (d == 3) printf("O\n");
  }

  return 0;
}
