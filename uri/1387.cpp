#include <cstdio>

int main()
{
  int l, r;
  while (scanf("%d%d", &l, &r) != EOF && l)
    printf("%d\n", l + r);
  return 0;
}
