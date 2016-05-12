#include <cstdio>

int main()
{
  int n;
  scanf("%d", &n);

  int d = 0;
  int m = n;
  while (m)
  {
    d++;
    m /= 10;
  }

  int p = 0;
  while (d)
  {
    m = 1;
    for (int i = 1; i < d; ++i)
      m *= 10;

    p <<= 1;
    if ((n / m) % 10 == 4)
      p += 1;
    else
      p += 2;

    d--;
  }

  printf("%d\n", p);

  return 0;
}
