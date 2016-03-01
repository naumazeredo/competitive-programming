#include <bits/stdc++.h>

int n, m;

int main() {
  scanf("%d%d", &n, &m);
  int moves = n - n/2;
  do {
    if (moves % m == 0) { printf("%d\n", moves); return 0; }
    moves++;
  } while (moves <= n);

  printf("-1\n");
  return 0;
}
