#include <cstdio>
#include <cmath>

int d[100];

bool palindrome(int n)
{
  int a = 0;
  while (n > 0)
  {
    d[a++] = n % 10;
    n /= 10;
  }

  for (int i = 0; i < a / 2; ++i)
    if (d[i] != d[a - i - 1])
      return false;
  return true;
}

int main()
{
  int t;
  scanf("%d", &t);

  int a, b, c;
  int sa, sb;
  for (int i = 1; i <= t; ++i)
  {
    printf("Case #%d: ", i);

    scanf("%d%d", &a, &b);

    sa = sqrt(a);
    sb = sqrt(b);

    if (a != sa * sa) sa++;

    c = 0;
    for (int j = sa; j <= sb; ++j)
      if (palindrome(j) && palindrome(j * j))
        c++;

    printf("%d\n", c);
  }

  return 0;
}
