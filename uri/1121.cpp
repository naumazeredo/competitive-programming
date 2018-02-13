#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int di[] = {-1, 0, 1,  0};
const int dj[] = { 0, 1, 0, -1};

int n, m, s;
int pi, pj, d;
char g[N][N];

int main() {
  while (scanf("%d%d%d", &n, &m, &s), n) {
    memset(g, 0, sizeof g);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char c;
        scanf(" %c", &c);
        if (c == '#') continue;

        g[i][j] = c;
        if (c == 'N') pi = i, pj = j, d = 0;
        if (c == 'L') pi = i, pj = j, d = 1;
        if (c == 'S') pi = i, pj = j, d = 2;
        if (c == 'O') pi = i, pj = j, d = 3;
      }
    }

    int ans = 0;
    for (int i = 0; i < s; i++) {
      char c;
      scanf(" %c", &c);

      if (c == 'F') {
        if (g[pi+di[d]][pj+dj[d]]) {
          pi += di[d];
          pj += dj[d];
          if (g[pi][pj] == '*') {
            g[pi][pj] = '.';
            ans++;
          }
        }
      }
      if (c == 'E') d = (d+3)%4;
      if (c == 'D') d = (d+1)%4;
    }

    printf("%d\n", ans);
  }

  return 0;
}
