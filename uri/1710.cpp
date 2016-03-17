#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[600][4];

map<string, int> d;
int ans;

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; ++i) scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    string p;

    for (int j = 0; j < m; ++j) p += '0'+(a[j][0]*x + a[j][1]*y + a[j][2]*z - a[j][3]>0);
    d[p]++;
    ans = max(ans, d[p]);
  }

  printf("%d\n", ans);
  return 0;
}
