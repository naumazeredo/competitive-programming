#include <bits/stdc++.h>
using namespace std;

int t, a, g[1000][1000], l;

int empty(int y, int x) {
  int res = 0;
  for (int i = -1; i <= 1; i++)
    for (int j = -1; j <= 1; j++)
      res += !g[y+i][x+j];
  return res;
}

bool receive() {
  int y, x;
  scanf("%d%d", &y, &x);

  if (!y and !x)
    return true;

  g[y][x] = 1;
  return false;
}

void send() {
  int by = 2, bx = 2, b = 0;
  for (int y = 2; y <= l-1; y++)
    for (int x = 2; x <= l-1; x++)
      if (empty(y, x) > b)
        by = y, bx = x, b = empty(y, x);

  printf("%d %d\n", by, bx);
  fflush(stdout);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    memset(g, 0, sizeof g);
    scanf("%d", &a);

    l = 1;
    for (; l*l < a; l++) ;

    do send(); while (!receive());
  }
  return 0;
}
