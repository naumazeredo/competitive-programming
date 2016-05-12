#include <bits/stdc++.h>
using namespace std;

int n;
int x[4], y[4];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);

  int a = -1;
  for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j)
    if (x[i] != x[j] && y[i] != y[j])
      a = abs(x[i]-x[j])*abs(y[i]-y[j]);

  printf("%d\n", a);

  return 0;
}
