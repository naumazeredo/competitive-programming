#include <cstdio>

int main()
{
  int h1, m1, h2, m2;
  while (scanf("%d%d%d%d", &h1, &m1, &h2, &m2) != EOF && (h1 || m1 || h2 || m2))
  {
    m1 += h1 * 60;
    m2 += h2 * 60;
    if (m2 < m1) m2 += 24 * 60;
    printf("%d\n", m2 - m1);
  }

  return 0;
}
