#include <bits/stdc++.h>
using namespace std;

int n;
int a[20000];
int g[20000];
int c;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  memset(g, 0, sizeof(g));
  c = 0;
  int inv = -1;
  while (c < n) {
    inv++;
    for (int i = 0; i < n; ++i)
      if (!g[i] && c >= a[i])
        g[i]=1, c++;
    if (c==n) break;
    inv++;
    for (int i = n-1; i >=0; --i)
      if (!g[i] && c >= a[i])
        g[i]=1, c++;
  }

  printf("%d\n", inv);

  return 0;
}
