#include <bits/stdc++.h>

int t, x;

int main() {
  for (int i = 0; i < 5; ++i) scanf("%d", &x), t += x;
  if (t == 0 or t%5) printf("-1\n");
  else printf("%d\n", t/5);
  return 0;
}
