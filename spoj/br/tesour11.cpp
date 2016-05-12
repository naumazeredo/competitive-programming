#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, k;
int px[200], py[200], pd[200];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) scanf("%d%d%d", &px[i], &py[i], &pd[i]);

  int m = 0, sx = -1, sy = -1;
  for (int y = 0; y < n and !m; ++y) {
    for (int x = 0; x < n and !m; ++x) {
      int ok = 1;
      for (int p = 0; p < k and ok; ++p)
        if (abs(y-py[p])+abs(x-px[p]) != pd[p])
          ok = 0;
      if (!ok) continue;

      if (sx!=-1) { m = 1; break; }
      sx = x;
      sy = y;
    }
  }

  if (m) printf("-1 -1\n");
  else printf("%d %d\n", sx, sy);

  return 0;
}
