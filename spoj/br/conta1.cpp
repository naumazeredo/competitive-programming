#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  scanf("%d", &n);

  int ans = 7;
  for (int i = 11; i <= n; i++) {
    if (11 <= i and i <= 30) ans += 1;
    if (31 <= i and i <= 100) ans += 2;
    if (101 <= i) ans += 5;
  }

  printf("%d\n", ans);
  return 0;
}
