#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
  scanf("%d%d", &a, &b);
  if (b > a) {
    printf("-1\n");
    return 0;
  }

  double x = b;
  double diff = a-x;
  int mod = 2;
  while (diff-2*x >= 0.0) diff-=2*x, mod+=2;

  if (diff > 1e-9 || diff < -1e-9) x += diff / mod;

  printf("%.10lf\n", x);

  return 0;
}
