#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  scanf("%d", &n);
  if (n == 1) printf("0\n");
  else if (n == 2) printf("0 1\n");
  else {
    int fib1 = 0, fib2 = 1;
    printf("0 1");
    for (int i = 3; i <= n; i++) {
      int fib3 = fib1 + fib2;
      printf(" %d", fib3);

      fib1 = fib2;
      fib2 = fib3;
    }
    printf("\n");
  }
  return 0;
}
