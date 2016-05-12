#include <bits/stdc++.h>
using namespace std;

int n;
int h[100005];
int q[100005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &h[i]);

  int g = 0;
  for (int i = n-1; i >= 0; --i)
    q[i] = g, g = max(h[i], g);

  for (int i = 0; i < n; ++i)
    printf("%d ", (q[i] >= h[i]) ? (q[i]-h[i]+1) : 0);
  printf("\n");

  return 0;
}
