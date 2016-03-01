#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, m, q, l, u;
int h[1000][1000];

int main() {
  while (scanf("%d%d", &n, &m) != EOF and n and m) {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &h[i][j]);

    scanf("%d", &q);
    for (int t = 0; t < q; ++t) {
      scanf("%d%d", &l, &u);

      vector<int> a, b;
      for (int i = 0; i < n; ++i) {
        int p = lower_bound(h[i], h[i]+m, l)-h[i];
        if (p < m and h[i][p] <= u) a.pb(p);
      }
      for (int i = 0; i < n; ++i) {
        int p = upper_bound(h[i], h[i]+m, u)-h[i];
        if (p > 0 and h[i][p-1] >= l) b.pb(p);
      }

      int i = 0, j = 0, m = 0;
      while (j < a.size()) {
        m = max(m, min(j-i+1, b[j]-a[i]));
        if (b[j]-a[i]<=j-i) i++;
        j++;
      }

      printf("%d\n", m);
    }
    printf("-\n");
  }

  return 0;
}
