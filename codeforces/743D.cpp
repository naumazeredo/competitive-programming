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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5+5;

int n, a[N], u, v, p[N];
ll sz[N], res[N], ans;
vi adj[N];

void dfs(int u) {
  res[u] = -LINF;
  sz[u] = a[u];
  for (int v : adj[u]) if (v != p[u]) {
    p[v] = u; dfs(v);
    sz[u] += sz[v];
    res[u] = max(res[u], res[v]);
  }
  res[u] = max(res[u], sz[u]);

  vector<ll> ch;
  for (int v : adj[u]) if (v != p[u]) ch.pb(res[v]);

  if (ch.size() > 1) {
    sort(ch.begin(), ch.end());
    ans = max(ans, ch[ch.size()-1]+ch[ch.size()-2]);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d%d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }

  ans = -LINF;
  dfs(1);

  if (ans == -LINF) printf("Impossible\n");
  else printf("%lld\n", ans);

  return 0;
}
