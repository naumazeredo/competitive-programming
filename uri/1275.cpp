#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int g[10][10], v[10][10], a[10][10], p[10][10];
int r[50], c[50], k[50];
int ans = 0x3f3f3f3f, res;

void reset() {
  ans = 0x3f3f3f3f;
  memset(g, 0, sizeof(g));

  for (int i = 0; i <= n+1; i++) g[i][0] = g[i][m+1] = -1;
  for (int j = 0; j <= m+1; j++) g[0][j] = g[n+1][j] = -1;
}

int ok(int i, int j) {
  int x = g[i-1][j-1];
  if (x > 0) {
    if (k[x] == -1) return 1;
    return a[i-1][j-1] == k[x];
  }
  return 1;
}

void print() {
  printf("ans: %d\n", ans);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", p[i][j]);
    printf("\n");
  }
  printf("\n");
}

void bt(int i, int j) {
  if (j > m+1) {
    bt(i+1, 0);
    return;
  }

  if (i > n+1) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!g[i][j] and !v[i][j]) return;

    ans = min(ans, res);
    return;
  }

  if (!ok(i, j)) return;

  if (g[i][j] or !(!v[i][j] and g[i][j+1]) or !(!v[i][j] and g[i+1][j]))
    bt(i, j+1);

  if (!g[i][j] and !v[i][j]) {
    res++;

    v[i][j]++;
    for (int jj = j-1; jj >= 1 and !g[i][jj]; jj--) v[i][jj]++;
    for (int jj = j+1; jj <= m and !g[i][jj]; jj++) v[i][jj]++;

    for (int ii = i-1; ii >= 1 and !g[ii][j]; ii--) v[ii][j]++;
    for (int ii = i+1; ii <= n and !g[ii][j]; ii++) v[ii][j]++;

    a[i-1][j]++;
    a[i+1][j]++;
    a[i][j-1]++;
    a[i][j+1]++;

    p[i][j] = 1;
    bt(i, j+1);
    p[i][j] = 0;

    res--;

    v[i][j]--;
    for (int jj = j-1; jj >= 1 and !g[i][jj]; jj--) v[i][jj]--;
    for (int jj = j+1; jj <= m and !g[i][jj]; jj++) v[i][jj]--;

    for (int ii = i-1; ii >= 1 and !g[ii][j]; ii--) v[ii][j]--;
    for (int ii = i+1; ii <= n and !g[ii][j]; ii++) v[ii][j]--;

    a[i-1][j]--;
    a[i+1][j]--;
    a[i][j-1]--;
    a[i][j+1]--;
  }
}

int main() {
  while (~scanf("%d%d", &n, &m) and n and m) {
    reset();

    scanf("%d", &b);
    for (int i = 1; i <= b; i++) {
      scanf("%d%d%d", &r[i], &c[i], &k[i]);
      g[r[i]][c[i]] = i;
    }

    bt(0, 0);

    if (ans == 0x3f3f3f3f) printf("No solution\n");
    else printf("%d\n", ans);
  }
  return 0;
}
