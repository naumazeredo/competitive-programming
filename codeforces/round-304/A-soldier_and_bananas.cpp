#include <cstdio>

int k, n, w;

int main() {
  scanf("%d%d%d", &k, &n, &w);
  int b = ((w + 1) * w * k) / 2 - n;
  printf("%d\n", (b > 0) ? b : 0);
}
