#include <cstdio>

int main()
{
  int q, d, p;
  while (scanf("%d%d%d", &q, &d, &p) != EOF && q)
  {
    int pag = (p * q * d) / (p - q);
    printf("%d pagina%s\n", pag, (pag > 1 ? "s" : ""));
  }

  return 0;
}
