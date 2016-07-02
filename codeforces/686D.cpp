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
const int N = 3e5+5;

int n, q, x;
int p[N], c[N], sz[N];
vi adj[N];

void dfs(int u) {
  sz[u] = 1;
  for (int v : adj[u]) {
    dfs(v);
    sz[u] += sz[v];
  }

  c[u] = u;
  for (int v : adj[u]) {
    if (sz[v] > sz[u]/2) {
      c[u] = c[v];
      while (2*sz[c[u]] < sz[u]) c[u] = p[c[u]];
    }
  }
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; ++i) scanf("%d", &p[i]), adj[p[i]].pb(i);
  dfs(1);
  for (int i = 0; i < q; ++i) {
    scanf("%d", &x);
    printf("%d\n", c[x]);
  }
  return 0;
}
