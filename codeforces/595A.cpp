#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
  scanf("%d%d", &n, &m);
  int c = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x, y;
      scanf("%d%d", &x, &y); c += x||y;
    }
  }
  printf("%d\n", c);
  return 0;
}
