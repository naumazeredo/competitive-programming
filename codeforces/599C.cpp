#include <bits/stdc++.h>
using namespace std;

int n;
int h[100005];
int smin[100005];
int pmax[100005];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) scanf("%d", &h[i]);

  smin[n-1] = h[n-1];
  for (int i = n-2; i >= 0; --i) smin[i] = min(h[i], smin[i+1]);

  pmax[0] = h[0];
  for (int i = 1; i < n; ++i) pmax[i] = max(h[i], pmax[i-1]);

  int np = 1, l = 0;
  for (int i = 0; i < n-1; ++i) if (pmax[i] <= smin[i+1]) np++;

  printf("%d\n", np);

  return 0;
}
