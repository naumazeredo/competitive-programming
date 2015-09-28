#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,  0,  1, 1, 1, 0, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 1,  1,  0};
char s[200][200];
int r, c;

int ff(int y, int x) {
  if (s[y][x] != '*')
    return 0;

  int cnt = 1;
  s[y][x] = '.';
  for (int i = 0; i < 8; ++i)
    if (x+dx[i]>=0 && x+dx[i]<c && y+dy[i]>=0 && y+dy[i]<r)
      cnt+=ff(y+dy[i], x+dx[i]);

  return cnt;
}

int main() {
  while (scanf("%d%d", &r, &c) != EOF && r && c) {
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
      scanf(" %c", &s[i][j]);

    int cnt = 0;
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
      if (ff(i,j) == 1)
        cnt++;

    printf("%d\n", cnt);
  }
  return 0;
}
