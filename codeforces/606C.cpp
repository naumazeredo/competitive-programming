#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int n;
int a[MAXN];
int d[MAXN];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

  int m = 0;
  for (int i = 1; i <= n; ++i) {
    d[a[i]] = 1 + d[a[i]-1];
    m = max(m, d[a[i]]);
  }

  printf("%d\n", n-m);

  return 0;
}
