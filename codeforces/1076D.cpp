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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5+5;

int n, m, k;
vector<piii> edges;
vector<int> adj[N];

ll dist[N];
int up[N];

int t;
vector<int> ans;

void dijkstra() {
  memset(dist, 63, sizeof dist);
  memset(up, -1, sizeof up);

  priority_queue<pll> pq;
  dist[1] = 0;
  pq.push({ 0, 1 });

  while (pq.size()) {
    ll u = pq.top().nd;
    ll d = -pq.top().st;
    pq.pop();

    if (dist[u] < d) continue;
    for (auto x : adj[u]) {
      int v = edges[x].nd.st;
      int w = edges[x].nd.nd;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({ -dist[v], v });
        up[v] = x;
      }
    }
  }
}

void rebuild() {
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 1; i <= n; i++) if (up[i] != -1) adj[edges[up[i]].st].push_back(up[i]);
}

void reduce(int u) {
  for (auto x : adj[u]) {
    int v = edges[x].nd.st;
    reduce(v);
  }
  if (t) t--;
  else if (up[u] != -1) ans.push_back(up[u]);
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int u, v, w, i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    int id = edges.size();
    edges.push_back({ u, { v, w } });
    edges.push_back({ v, { u, w } });
    adj[u].push_back(id);
    adj[v].push_back(id+1);
  }

  /*
  for (int i = 1; i <= n; i++) {
    printf("%d: ", i);
    for (int v : adj[i]) printf("%d ", v);
    printf("\n");
  }
  */

  dijkstra();
  rebuild();

  /*
  for (int i = 1; i <= n; i++) {
    printf("%d: ", i);
    for (int v : adj[i]) printf("%d ", v);
    printf("\n");
  }
  */

  t = max(0, n-1 - k);
  reduce(1);

  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x/2+1);
  printf("\n");

  return 0;
}
