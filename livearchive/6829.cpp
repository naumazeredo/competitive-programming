#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int n, f, a, b, c;
vector<pii> adj[100005];
int p[100005];

int g;

int dfs(int u, int c) {
  if (p[u]) g = max(g, c);

  int tot = 0, ok = p[u];
  for (int i = 0; i < adj[u].size(); ++i) {
    int x = dfs(adj[u][i].st, c+adj[u][i].nd);
    if (x >= 0) ok=1, tot += x + adj[u][i].nd;
  }

  if (ok) return tot;
  return -1;
}

int main() {
  while (scanf("%d%d", &n, &f) != EOF) {
    for (int i = 0; i <= n; ++i) adj[i].clear();
    memset(p, 0, sizeof(p));

    for (int i = 0; i < n-1; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      adj[a].pb(mp(b, c));
    }
    for (int i = 0; i < f; ++i) scanf("%d", &a), p[a]=1;

    g = 0;
    printf("%d\n", dfs(1, 0)-g);
  }
  return 0;
}
