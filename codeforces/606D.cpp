#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n, m;
iii e[100005];
int t[100005];
ii r[100005];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d", &e[i].first, &e[i].second.first), e[i].second.second = i, e[i].second.first = -e[i].second.first;
  sort(e+1, e+m+1);
  /*
  for (int i = 1; i <= m; ++i)
    printf("%d %d\n", e[i].first, e[i].second.first);
  */

  for (int i = 2; i <= n; ++i)
    t[i] = i;

  int cur = 1;
  int nex = 2;
  for (int i = 1; i <= m; ++i) {
    if (e[i].second.first) r[e[i].second.second] = ii(1, ++cur), nex=2;
    else {
      while (t[nex] >= cur && nex <= cur) nex++;
      if (nex > cur) { printf("-1\n"); return 0; }
      r[e[i].second.second] = ii(nex, ++t[nex]);
    }
  }

  for (int i = 1; i <= m; ++i)
    printf("%d %d\n", r[i].first, r[i].second);

  return 0;
}
