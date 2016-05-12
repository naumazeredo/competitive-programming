#include <bits/stdc++.h>
using namespace std;

int n;
int a[2][55];
int b[55];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i)
    scanf("%d", &a[0][i]);
  for (int i = 0; i < n-1; ++i)
    scanf("%d", &a[1][i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);

  int m[2] = {100000, 100000};
  for (int i = 0; i < n; ++i) {
    int k = 0;
    for (int j = 0; j < i; ++j)
      k += a[0][j];
    k+=b[i];
    for (int j = i; j < n-1; ++j)
      k += a[1][j];

    if (k <= m[0])
      m[1] = m[0], m[0] = k;
    else if (k < m[1])
      m[1] = k;
  }

  printf("%d\n", m[0] + m[1]);
  return 0;
}
