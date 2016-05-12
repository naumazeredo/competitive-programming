#include <bits/stdc++.h>
using namespace std;

int n;

int prime(int x) {
  for (int i=2; i*i<=x; ++i)
    if (x%i==0)
      return 0;
  return 1;
}

int main() {
  scanf("%d", &n);
  if (prime(n)) {
    printf("1\n%d\n", n);
    return 0;
  } else {
    printf("3\n3 ");
    n-=3;
    for (int i=3;;i+=2) {
      if (prime(i) && prime(n-i)) {
        printf("%d %d\n", i, n-i);
        return 0;
      }
    }
  }
  return 0;
}
