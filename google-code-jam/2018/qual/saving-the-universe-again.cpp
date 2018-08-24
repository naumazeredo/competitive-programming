#include <bits/stdc++.h>
using namespace std;

int t, d, n;
char s[100];

int total() {
  int res = 0, p = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S') res += p;
    else p *= 2;
  }
  return res;
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    printf("Case #%d: ", tt);
    scanf("%d%s", &d, s);
    n = strlen(s);

    int ans = 0;
    while (total() > d) {
      int ok = 0;
      for (int i = n-1; i > 0; i--) {
        if (s[i] == 'S' and s[i-1] == 'C') {
          swap(s[i], s[i-1]);
          ok = 1;
          break;
        }
      }
      if (!ok) break;
      ans++;
    }

    if (total() <= d) printf("%d\n", ans);
    else printf("IMPOSSIBLE\n");
  }
  return 0;
}
