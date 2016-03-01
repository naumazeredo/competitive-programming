#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, x;
  while (scanf("%d%d%d", &n, &m, &x) != EOF && n != 0) {
    x--;
    int y = 0;

    string s[20];
    int v[20][20] = {};

    for (int i = 0; i < n; ++i)
      cin >> s[i];

    int loop = 0;
    int cnt = 1;
    v[x][y] = cnt;
    while (true) {
      char c = s[y][x];
      if (c == 'N') {
        y--;
        if (y<0) break;
      } else if (c == 'S') {
        y++;
        if (y>=n) break;
      } else if (c == 'E') {
        x++;
        if (x>=m) break;
      } else if (c == 'W') {
        x--;
        if (x<0) break;
      }

      if (v[x][y]) {
        loop = cnt + 1 - v[x][y];
        break;
      }

      cnt++;
      v[x][y] = cnt;
    }

    if (!loop)
      printf("%d step(s) to exit\n", cnt);
    else
      printf("%d step(s) before a loop of %d step(s)\n", cnt - loop, loop);
  }
  return 0;
}
