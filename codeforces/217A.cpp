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
const int N = 1e3+5;

int n, x[N], y[N], vis[N];
vi xx[N], yy[N];

int dfs(int u) {
  vis[u] = 1;
  for (auto v : xx[x[u]]) if (v != u and !vis[v])
    dfs(v);
  for (auto v : yy[y[u]]) if (v != u and !vis[v])
    dfs(v);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &x[i], &y[i]),
    xx[x[i]].pb(i), yy[y[i]].pb(i);

  int ans = -1;
  for (int i = 0; i < n; ++i) if (!vis[i]) dfs(i), ans++;
  printf("%d\n", ans);
  return 0;
}
