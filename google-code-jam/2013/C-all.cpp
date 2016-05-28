#include <cstdio>
#include <cmath>

int d[100];

bool palindrome(long long n)
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
  for (long long j = 1; j <= 1e7; ++j)
    if (palindrome(j) && palindrome(j * j))
      printf("%lld\n", j);

  return 0;
}
