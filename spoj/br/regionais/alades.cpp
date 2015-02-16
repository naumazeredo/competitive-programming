#include <cstdio>
#include <algorithm>

int main()
{
  int h1, m1, h2, m2;

  while (scanf("%d%d%d%d", &h1, &m1, &h2, &m2) && (h1 || h2 || m1 || m2))
  {
    printf("%d\n", ((h2 - h1 + 24) * 60 + (m2 - m1)) % (24 * 60));
  }

  return 0;
}
