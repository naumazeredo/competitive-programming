#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n, m, x, y, w, s;
ll ss[N];

ll calc(ll x) {
  ll ans = 0;
  ll lo = 0, hi = w;
  while (lo<hi) {
    ll mid = (lo+hi+1)/2;
    if (mid*(mid+1)/2 <= x) lo = mid;
    else hi = mid-1;
  }

  return x*(lo+1)-ss[lo];
}

// Kosaraju - SCC O(V+E)
vi adj[N], adjt[N];
vi adjw[N], adjtw[N];
int ord[N], ordn, scc[N], sccn, vis[N];

ll sccsum[N];
vector<pii> sccadj[N];

void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) if (!vis[v]) dfs(v);
  ord[ordn++] = u;
}

void dfst(int u) {
  vis[u] = 0;
  for (int v : adjt[u]) if (vis[v]) dfst(v);
  scc[u] = sccn;
}

// scc adj
ll ans[N], sccvis[N];
ll sccdfs(int u) {
  if (sccvis[u]) return ans[u];
  ans[u] = sccsum[u];
  sccvis[u] = 1;

  for (auto x : sccadj[u]) {
    int v = x.st, w = x.nd;
    ans[u] = max(ans[u], sccsum[u] + w + sccdfs(v));
  }

  return ans[u];
}

int main() {
  for (ll i = 1; i < N; i++) ss[i] = ss[i-1]+i*(i+1)/2;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &x, &y, &w);
    adj[x].pb(y); adjw[x].pb(w);
    adjt[y].pb(x); adjtw[y].pb(w);
  }
  scanf("%d", &s);

  // kosaraju
  sccn = ordn = 1;
  for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
  for (int i = n; i > 0; --i) if (vis[ord[i]]) dfst(ord[i]), sccn++;

  // scc adj
  for (int u = 1; u <= n; u++) {
    int su = scc[u];
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i], w = adjw[u][i];
      int sv = scc[v];
      if (su != sv) sccadj[su].pb({ sv, w });
      else sccsum[su] += calc(w);
    }
  }

  printf("%lld\n", sccdfs(scc[s]));

  return 0;
}
