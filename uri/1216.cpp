#include <cstdio>

int main()
{
  char str[1024];
  int s=0, d, n = 0;
  while (fgets(str, 1024, stdin) != 0)
  {
    scanf("%d%*c", &d);
    s += d;
    n++;
  }

  printf("%.1f\n", (float)s / n);

  return 0;
}
