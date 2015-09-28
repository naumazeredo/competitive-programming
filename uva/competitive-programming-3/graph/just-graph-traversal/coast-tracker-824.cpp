#include <bits/stdc++.h>
using namespace std;

int rx, ry, rd;
int x, y, d;

int mapping(int a, int b) {
  if (a ==  1 && b ==  0) return 0;
  if (a ==  1 && b ==  1) return 1;
  if (a ==  0 && b ==  1) return 2;
  if (a == -1 && b ==  1) return 3;
  if (a == -1 && b ==  0) return 4;
  if (a == -1 && b == -1) return 5;
  if (a ==  0 && b == -1) return 6;
  return 7;
}

int main() {
  while (scanf("%d%d%d", &x, &y, &d) != EOF && x != -1) {
    rx = x; ry = y; rd = d;
    int m = 8;
    for (int i = 0; i < 8; ++i) {
      scanf("%d%d%d", &x, &y, &d);
      if (d == 0) continue;

      m = min(m, (mapping(x-rx, y-ry) - rd + 8) % 8);
    }

    cout << (rd + m + 6) % 8 << endl;
  }

  return 0;
}
