#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int w, h, n;
int m[N][N];
int a, b, x, y;

int main() {
  while (scanf("%d%d%d", &w, &h, &n), w or h or n) {
    memset(m, 0, sizeof m);

    for (int i = 0; i < n; i++) {
      scanf("%d%d%d%d", &a, &b, &x, &y);
      int x0 = min(a, x);
      int y0 = min(b, y);
      int x1 = max(a, x);
      int y1 = max(b, y);

      for (int i = y0; i <= y1; i++)
        for (int j = x0; j <= x1; j++)
          m[i][j] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= w; j++)
        ans += !m[i][j];

    if (ans == 1) printf("There is one empty spot.\n");
    else if (ans) printf("There are %d empty spots.\n", ans);
    else printf("There is no empty spots.\n");
  }

  return 0;
}
