#include <bits/stdc++.h>
using namespace std;

int n;
int rx[51], ry[51];

int main() {
  memset(rx, 0, sizeof(rx));
  memset(ry, 0, sizeof(ry));
  scanf("%d", &n);
  for (int i = 1; i <= n * n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (!rx[a] && !ry[b]) {
      printf("%d ", i);
      rx[a] = ry[b] = 1;
    }
  }
  printf("\n");

  return 0;
}
