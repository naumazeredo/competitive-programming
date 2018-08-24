// @subject: bridges, tree diameter, longest path DAG
// @diff: 3

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
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

int n, m, ans;
vector<int> adj[N];
set<pii> br;

vector<int> adj2[N];
int h[N], vis[N], cc[N], ccn;

// Articulation points and Bridges O(V+E)
int par[N], low[N], num[N], cnt;

void bridges(int u) {
  low[u] = num[u] = ++cnt;
  for (int v : adj[u]) {
    if (!num[v]) {
      par[v] = u;
      bridges(v);
      if (low[v] >  num[u]) br.insert({ u, v }), br.insert({ v, u });
      low[u] = min(low[u], low[v]);
    }
    else if (v != par[u]) low[u] = min(low[u], num[v]);
  }
}

void build(int u, int c) {
  vis[u] = 1;
  cc[u] = c;
  for (int v : adj[u]) if (!vis[v]) {
    if (br.count({ u, v })) {
      ccn++;
      build(v, ccn);
      adj2[cc[u]].push_back(cc[v]);
      adj2[cc[v]].push_back(cc[u]);
    } else {
      build(v, c);
    }
  }
}

void dfs(int u) {
  vis[u] = 1;
  h[u] = 0;

  vector<int> hc;

  for (int v : adj2[u]) if (!vis[v]) {
    h[v] = h[u]+1;
    dfs(v);
    hc.push_back(h[v]+1);
  }

  if (hc.size()) {
    sort(hc.begin(), hc.end(), greater<int>());
    h[u] = hc[0];
    ans = max(ans, h[u]);
    if (hc.size() > 1) ans = max(ans, hc[0]+hc[1]);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int u, v, i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bridges(1);
  build(1, 0);
  memset(vis, 0, sizeof vis);
  dfs(1);
  printf("%d\n", ans);
  return 0;
}
