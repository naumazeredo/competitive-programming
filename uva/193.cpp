#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int m, n, k, x, y;
vector<int> adj[200];

int u[200];
bitset<200> c, sol;

void bt(int x) {
  while (u[x] and x <= n) x++;
  if (x > n) {
    if (sol.count() < c.count()) sol = c;
    return;
  }

  if (!c[x]) {
    c.set(x);
    for (int i = 0; i < adj[x].size(); ++i) u[adj[x][i]]++;
    bt(x+1);
    for (int i = 0; i < adj[x].size(); ++i) u[adj[x][i]]--;
    c.reset(x);
  }
  bt(x+1);
}

int main() {
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 0; i < k; ++i) {
      scanf("%d%d", &x, &y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    memset(u, 0, sizeof(u));
    sol.reset();
    c.reset();
    bt(1);

    printf("%d\n", (int)sol.count());
    int cnt = 0;
    for (int i = 1; i <= n; ++i) if (sol[i]) printf("%d%c", i, cnt==sol.count()-1?'\n':' '), cnt++;
  }
  return 0;
}
