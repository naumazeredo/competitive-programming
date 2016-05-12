#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, m, a, b;
int adj[600][600];
int c[600];
int v[600];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    adj[a][b]=1;
    adj[b][a]=1;
    c[a]++;
    c[b]++;
  }

  for (int i = 1; i <= n; ++i) if (c[i]==n-1) v[i]=2;

  for (int i = 1; i <= n; ++i) if (!v[i]) { v[i] = 1; break; }
  for (int i = 1; i <= n; ++i)
    if (v[i] == 1) for (int j = i+1; j <= n; ++j)
      if (!v[j] and adj[i][j]) v[j] = 1;

  for (int i = 1; i <= n; ++i) if (!v[i]) { v[i] = 3; break; }
  for (int i = 1; i <= n; ++i)
    if (v[i] == 3) for (int j = i+1; j <= n; ++j)
      if (!v[j] and adj[i][j]) v[j] = 3;

  for (int i = 1; i <= n; ++i) if (!v[i]) { printf("No\n"); return 0; }
  for (int i = 1; i <= n; ++i) for (int j = i+1; j <= n; ++j)
    if (v[i] == v[j] and !adj[i][j]) { printf("No\n"); return 0; }

  printf("Yes\n");
  for (int i = 1; i <= n; ++i) printf("%c", 'a'-1+v[i]); printf("\n");

  return 0;
}
