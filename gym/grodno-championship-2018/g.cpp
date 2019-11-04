// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m, k, p;
vector<pll> adj[N];
vector<int> sc;

ll dist[N];
int comp[N], par[N], vis[N];

vector<int> ans;

void dijkstra() {
  memset(dist, 63, sizeof dist);

  priority_queue<pii> pq;
  for (auto x : sc) dist[x] = 0, comp[x] = x, pq.push({ 0, x }), par[x] = x;

  while (pq.size()) {
    int du = -pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist[u] < du) continue;
    for (auto x : adj[u]) {
      int v = x.first;
      ll w = x.second;

      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        comp[v] = comp[u];
        par[v] = u;
        pq.push({ -dist[v], v });
      }
    }
  }
}

bool dfs(int u) {
  //db(u _ comp[u]);
  if (vis[u]) return 0;
  vis[u] = 1;
  if (u == n) { ans.push_back(n); return 1; }
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i].first;
    ll w = adj[u][i].second;
    //db(v _ w _ comp[v]);

    if (comp[u] == comp[v] and dist[u] + w == dist[v] and dfs(v)) {
      ans.push_back(u); return 1;
    }

    if (comp[u] != comp[v] and dist[u] + dist[v] + w <= p and dfs(comp[v])) {
      vector<int> pa;
      int x = v;
      while (x != comp[v]) {
        pa.push_back(x);
        x = par[x];
      }
      reverse(pa.begin(), pa.end());
      pa.push_back(u);
      for (auto y : pa) ans.push_back(y);
      return 1;
    }
  }
  return 0;
}

void solve() {
  dijkstra();

  if (!dfs(1)) {
    printf("-1\n");
    return;
  }

  printf("%d\n", (int)ans.size());
  reverse(ans.begin(), ans.end());
  for (int x : ans) printf("%d ", x);
  printf("\n");
}

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  for (int a, i = 0; i < k; i++) {
    scanf("%d", &a);
    sc.push_back(a);
  }

  sc.push_back(1); sc.push_back(n);
  sort(sc.begin(), sc.end());
  sc.erase(unique(sc.begin(), sc.end()), sc.end());

  for (int a, b, c, i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back({ b, c });
    adj[b].push_back({ a, c });
  }

  solve();

  return 0;
}
