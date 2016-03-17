#include <bits/stdc++.h>
using namespace std;

int n, m, x;

int main() {
  scanf("%d%d", &n, &m);

  int c = 0;
  for (int i = 0; i < n; ++i) {
    int r = 1;
    for (int j = 0; j < m; ++j) scanf("%d", &x), r &= (x>0);
    c += r;
  }

  printf("%d\n", c);
  return 0;
}
