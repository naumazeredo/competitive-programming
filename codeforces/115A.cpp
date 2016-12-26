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
const int N = 2e3+5;

int n, p[N], vis[N];
vi adj[N];

int dfs(int u, int h) {
  int res = h;
  for (int v : adj[u]) res = max(res, dfs(v, h+1));
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    if (~p[i]) adj[p[i]].pb(i);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) if (p[i]==-1)
    ans = max(ans, dfs(i, 1));
  printf("%d\n", ans);

  return 0;
}
