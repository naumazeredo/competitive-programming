#include <cstdio>

int exp(int x, int y, int mod)
{
  if (y == 0)
    return 1;
  if (y == 1)
    return x % mod;

  int r = exp(x, y/2, mod);
  if (y % 2 == 0)
    return (r * r) % mod;
  else
    return ((x % mod) * ((r * r) % mod)) % mod;
}

int main()
{
  int x, y, n, c;

  scanf("%d", &c);

  for (int i = 0; i < c; ++i)
  {
    scanf("%d%d%d", &x, &y, &n);
    printf("%d\n", exp(x, y, n));
  }

  return 0;
}
