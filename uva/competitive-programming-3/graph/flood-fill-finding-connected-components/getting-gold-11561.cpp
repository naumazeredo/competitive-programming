#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 1, 0, -1};
int dy[] = {-1, 0, 1,  0};
char s[100][100];
int sx, sy;
int w, h;

int ff(int y, int x) {
  if (s[y][x] == '#' || s[y][x] == 'T')
    return 0;

  int c = 0;

  if (s[y][x]=='G')
    c++;

  s[y][x]='#';

  for (int i = 0; i < 4; ++i)
    if (x+dx[i]>=0 && x+dx[i]<w && y+dy[i]>=0 && y+dy[i]<h && s[y+dy[i]][x+dx[i]] == 'T')
      return c;

  for (int i = 0; i < 4; ++i)
    if (x+dx[i]>=0 && x+dx[i]<w && y+dy[i]>=0 && y+dy[i]<h)
      c+=ff(y+dy[i], x+dx[i]);
  return c;
}

int main() {
  while (scanf("%d%d", &w, &h) != EOF) {
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
      scanf(" %c", &s[i][j]);
      if (s[i][j] == 'P')
        sx = j, sy = i;
    }

    printf("%d\n", ff(sy, sx));
  }

  return 0;
}
