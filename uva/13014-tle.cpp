#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX_N = 1e5+5;

int n, m;
priority_queue<ii> ss[MAX_N];
int dp[MAX_N];
int acc[MAX_N];

int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    acc[0]=0;
    for (int i = 0; i < n; ++i) {
      int e;
      scanf("%d", &e);
      acc[i+1]=acc[i]+e;
    }
    for (int i = 0; i < m; ++i) {
      int l, s, c;
      scanf("%d%d%d", &l, &s, &c);
      ss[l-1].push(ii(-c, s));
    }
    for (int i = 0; i <= n; ++i)
      fprintf(stderr, "%d ", acc[i]);
    fprintf(stderr, "\n");

    //memset(dp, -1, sizeof(dp));
    for (int i = 0; i < MAX_N; ++i) dp[i] = 2e9;

    dp[0]=0;
    int x = 0, l = x+1;
    while (x != n && dp[x] != 2e9) {
      fprintf(stderr, "x: %d\n", x);
      fprintf(stderr, "pq size: %d\n", (int)ss[x].size());
      l = x+1;

      while (!ss[x].empty()) {
        ii sh = ss[x].top(); ss[x].pop();

        fprintf(stderr, "shop: %d %d\n", -sh.first, sh.second);
        fprintf(stderr, "value: %d\n", acc[x]+sh.second);

        int e = upper_bound(acc+l, acc+n+1, acc[x]+sh.second) - acc;

        fprintf(stderr, "upper: %d\n", e);

        for (int i = l; i < e; ++i) dp[i] = min(dp[i], dp[x]-sh.first);
        l = e;
      }
      x++;

      for (int i = 0; i <= n; ++i)
        fprintf(stderr, "%d ", dp[i]);
      fprintf(stderr, "\n\n");
    }

    if (dp[n] == 2e9) printf("-1\n");
    else printf("%d\n", dp[n]);
  }
  return 0;
}
