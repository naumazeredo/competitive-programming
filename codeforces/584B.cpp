#include <bits/stdc++.h>
using namespace std;

const int m = 1e9+7;
int n;

long long modularExponential(long long base, int p, int modulo)
{
  if (p == 0) return 1;
  else if (p== 1) return base % modulo;
  else
  {
    long long result = modularExponential(base, p/2, modulo);

    if (p%2 == 0)
      return (result * result) % modulo;
    else
    {
      long long basemod = base % modulo;
      long long resmod = (result * result) % modulo;
      return (basemod * resmod) % modulo;
    }
  }
}

int main() {
  scanf("%d", &n);

  long long a = modularExponential(27, n, m);
  long long b = modularExponential( 7, n, m);
  //printf("a: %lld\n", a);
  //printf("b: %lld\n", b);

  printf("%d\n", (int)((a-b+m)%m));
  return 0;
}
