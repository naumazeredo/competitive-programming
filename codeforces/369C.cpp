#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, x, y, t, p[N], sz[N];
vi adj[N], adjt[N];
vi ans;

void dfs(int u) {
  int s = 0;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    int t = adjt[u][i];
    if (v != p[u])
      p[v] = u, sz[v] = t, dfs(v), s += sz[v];
  }

  if (!s and sz[u]) ans.pb(u);
  sz[u] += s;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d%d%d", &x, &y, &t);
    adj[x].pb(y); adjt[x].pb(t-1);
    adj[y].pb(x); adjt[y].pb(t-1);
  }

  dfs(1);
  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x);
  printf("\n");

  return 0;
}
