#include <cstdio>

int main()
{
  int a, b, c;
  while (scanf("%d%d%d", &a, &b, &c) != EOF)
  {
    if (a == b && b == c) printf("*\n");
    else if (a != b && b == c) printf("A\n");
    else if (a != b && b != c) printf("B\n");
    else if (a == b && b != c) printf("C\n");
  }

  return 0;
}
