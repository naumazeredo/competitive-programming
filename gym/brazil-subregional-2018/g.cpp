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

struct edge { int v, c; };

vector<edge> edges;
vector<int> adj[N];
int s, t, ptr[N], h[N], pa[N];

void reset() {
  for (int i = 0; i < N; i++) adj[i].clear();
  edges.clear();
}

void add_edge(int u, int v, int c) {
  int x = edges.size();
  edges.push_back({ v, c });
  edges.push_back({ u, 0 });

  adj[u].push_back(x);
  adj[v].push_back(x^1);
}

int bfs() {
  memset(h, 0, sizeof h);
  queue<int> q;
  q.push(s);
  h[s] = 1;
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int e : adj[u]) if (edges[e].c and !h[edges[e].v]) {
      h[edges[e].v] = h[u]+1;
      q.push(edges[e].v);
    }
  }

  return h[t];
}

int dfs(int u) {
  for (int& i = ptr[u]; i < (int)adj[u].size(); i++) {
    int e = adj[u][ptr[u]], v = edges[e].v, c = edges[e].c;
    if (h[v] == h[u]+1 and c) {
      pa[v] = e;
      if (v == t) return c;
      int x = dfs(v);
      if (x > 0) return min(c, x);
    }
  }
  return 0;
}

int max_flow() {
  int mf = 0;
  while (bfs()) {
    memset(ptr, 0, sizeof ptr);
    int f = 0;
    while ((f = dfs(s))) {
      int x = t;
      while (x != s) {
        edges[pa[x]].c -= f;
        edges[pa[x]^1].c += f;
        x = edges[pa[x]^1].v;
      }
      mf += f;
    }
  }
  return mf;
}

int p, r, c, sum;
int d[N], e[N];
piii conn[N];

int solve(int x) {
  reset();
  s = 1; t = p+r+2;
  for (int i = 1; i <= p; i++) add_edge(s, 1+i, d[i]);
  for (int i = 1; i <= r; i++) add_edge(1+p+i, t, e[i]);
  for (int i = 0; i < c; i++) if (conn[i].st <= x) add_edge(1+conn[i].nd.st, 1+p+conn[i].nd.nd, INF);

  int mf = max_flow();
  return (mf == sum);
}

int main() {
  scanf("%d%d%d", &p, &r, &c);
  for (int i = 1; i <= p; i++) scanf("%d", &d[i]), sum += d[i];
  for (int i = 1; i <= r; i++) scanf("%d", &e[i]);
  for (int i = 0; i < c; i++) scanf("%d%d%d", &conn[i].nd.st, &conn[i].nd.nd, &conn[i].st);

  int lo = 1, hi = 1e6+1;
  while (lo < hi) {
    int md = (lo+hi)/2;
    if (solve(md)) hi = md;
    else lo = md+1;
  }

  printf("%d\n", solve(lo) ? lo : -1);

  return 0;
}
