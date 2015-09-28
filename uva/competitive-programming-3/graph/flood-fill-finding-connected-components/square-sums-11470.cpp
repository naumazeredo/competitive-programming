#include <bits/stdc++.h>
using namespace std;

int s[20];
int m[20][20];
int n;

void solve() {
  memset(s, 0, sizeof(s));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int p = min(min(i, j), min(n-1-i, n-1-j));
      s[p]+=m[i][j];
    }
  }
}

int main() {
  int t = 1;
  while (scanf("%d", &n) != EOF && n) {
    printf("Case %d: ", t++);

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
      scanf("%d", &m[i][j]);

    solve();
    printf("%d", s[0]);
    for (int i = 1; i < (n+1)/2; ++i)
      printf(" %d", s[i]);
    printf("\n");
  }
  return 0;
}
