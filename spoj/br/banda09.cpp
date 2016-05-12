#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, m, x, y, z;
int g[105][105];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d%d%d", &x, &y, &z), g[x][y] = z, g[y][x] = z;

  int t = 0;
  for (int i = 1; i <= n; ++i) for (int j = i+1; j <= n; ++j) for (int k = j+1; k <= n; ++k)
    if (g[i][j] + g[j][k] + g[i][k] >= t) t = g[i][j] + g[j][k] + g[i][k], x = i, y = j, z = k;
  printf("%d %d %d\n", x, y, z);
  return 0;
}
