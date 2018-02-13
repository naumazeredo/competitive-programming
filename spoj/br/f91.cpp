#include <bits/stdc++.h>
using namespace std;

int n;

int f91(int n) {
  if (n <= 100) return f91(f91(n+11));
  return n-10;
}

int main() {
  while (scanf("%d", &n), n) {
    printf("f91(%d) = %d\n", n, f91(n));
  }
  return 0;
}
