#include <bits/stdc++.h>
using namespace std;

int n, l, s, t, x;
int g[105][105];
int r[105][105];
int aux[105][105];

void fastexpmat(int q, int m) {
  memset(r, 0, sizeof(r));
  for (int i = 1; i <= n; ++i) r[i][i] = 1;

  while (q) {
    if (q&1) {
      //r = (r*p)%m;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          int v = 0;
          for (int k = 1; k <= n; ++k) v = (v+(r[i][k]*g[k][j])%m)%m;
          aux[i][j] = v;
        }
      }

      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
          r[i][j] = aux[i][j];
    }

    //p = (p*p)%m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        int v = 0;
        for (int k = 1; k <= n; ++k) v = (v+(g[i][k]*g[k][j])%m)%m;
        aux[i][j] = v;
      }
    }

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        g[i][j] = aux[i][j];

    q >>= 1;
  }
}

int main() {
  while (~scanf("%d%d%d%d", &n, &l, &s, &t)) {
    memset(g, 0, sizeof(g));

    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < 4; ++j)
        scanf("%d", &x), g[i][x]++;

    fastexpmat(l, 10000);
    printf("%d\n", r[s][t]);
  }
  return 0;
}
