#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, m;
int g[40][40];

int dx[] = {1, 1, -1, -1},
    dy[] = {-1, 1, 1, -1};

int bt(int y, int x) {
  if (g[y][x] != 1) return 0;
  g[y][x] = 0;

  int res = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    int nx2 = nx+dx[i], ny2 = ny+dy[i];
    if (nx >= 0 and nx < m and ny >= 0 and ny < n and
        nx2 >= 0 and nx2 < m and ny2 >= 0 and ny2 < n and
        g[ny][nx] == 2 and g[ny2][nx2] == 0) {
      g[ny][nx] = 0;
      g[ny2][nx2] = 1;
      res = max(res, bt(ny2, nx2)+1);
      g[ny2][nx2] = 0;
      g[ny][nx] = 2;
    }
  }
  g[y][x] = 1;

  return res;
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF and n and m) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m/2 + (m%2?i%2==0:0); ++j) {
        int x = 2*j+i%2;
        scanf("%d", &g[i][x]);
      }
    }

    /*
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) printf("%d ", g[i][j]);
      printf("\n");
    }
    */

    int res = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
      res = max(res, bt(i, j));

    printf("%d\n", res);
  }
  return 0;
}
