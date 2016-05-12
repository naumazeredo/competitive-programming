#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n, m;
int adj[405][405][2];
int cost[405][2];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a][b][0]=1;
    adj[b][a][0]=1;
  }

  for (int i = 1; i <= n; ++i) for (int j = i+1; j <= n; ++j)
    if (!adj[i][j][0]) adj[i][j][1]=1, adj[j][i][1]=1;

  /*
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) printf("%d ", adj[i][j][0]);
    printf("\n");
  }
  printf("\n");

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) printf("%d ", adj[i][j][1]);
    printf("\n");
  }
  printf("\n");
  */

  int a=-1, b=-1;

  queue<ii> q;
  q.push(ii(0, 1));

  while (!q.empty()) {
    ii x = q.front(); q.pop();
    int c = x.first, u = x.second;

    if (u == n) {a = c; break;}

    if (cost[u][0] != 0) continue;

    cost[u][0] = c;
    for (int i = 1; i <= n; ++i)
      if (adj[u][i][0]) q.push(ii(c+1, i));
  }

  while (!q.empty()) q.pop();
  q.push(ii(0, 1));

  while (!q.empty()) {
    ii x = q.front(); q.pop();
    int c = x.first,
        u = x.second;

    if (u == n) {b = c; break;}

    if (cost[u][1] != 0) continue;

    cost[u][1] = c;
    for (int i = 1; i <= n; ++i)
      if (adj[u][i][1]) q.push(ii(c+1, i));
  }

  if (a>0 && b>0) printf("%d\n", max(a, b));
  else printf("-1\n");

  return 0;
}
