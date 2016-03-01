#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,  0,  1, 1, 1, 0, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 1,  1,  0};

int m, n;
char s[200][200];

int ff(int y, int x, char w, char e) {
  if (s[y][x]!=w)
    return 0;

  int c = 1;
  s[y][x]=e;
  for (int i = 0; i < 8; ++i)
    if (y+dy[i]>=0 && y+dy[i]<m && x+dx[i]>=0 && x+dx[i]<n)
      c += ff(y+dy[i], x+dx[i], w, e);
  return c;
}

int main() {
  while (scanf("%d%d", &m, &n) != EOF && m && n) {
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
      scanf(" %c", &s[i][j]);

    int c = 0;
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
      c += (ff(i, j, '@', '.')>0);

    printf("%d\n", c);
  }
  return 0;
}
