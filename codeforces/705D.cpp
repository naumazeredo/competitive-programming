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
const int N = 1e4+5, MAXN = 5010, MAXE = MAXN*MAXN;

int n, s, e, x[N], a[N], b[N], c[N], d[N];

//Min-Cost Max-Flow
#define SET(p) memset(p, -1, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))

int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN], dist[MAXN];
int cap[MAXE], cost[MAXE], nxt[MAXE], to[MAXE], from[MAXE];

inline void init(int _src, int _snk, int nodes) {
  SET(fin);
  nNode = nodes, nEdge = 0;
  src = _src, snk = _snk;
}

inline void addEdge(int u, int v, int _cap, int _cost) {
  from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap, cost[nEdge] = _cost;
  nxt[nEdge] = fin[u], fin[u] = nEdge++;

  from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] = -(_cost);
  nxt[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bellman() {
  int iter, u, v, i;
  bool flag = true;

  MEM(dist, 0x7f);
  SET(pre);
  dist[src] = 0;

  for(iter = 1; iter < nNode && flag; iter++) {
    flag = false;
    for(u = 0; u < nNode; u++) {
      for(i = fin[u]; i >= 0; i = nxt[i]) {
        v = to[i];

        if(cap[i] && dist[v] > dist[u] + cost[i]) {
          dist[v] = dist[u] + cost[i];
          pre[v] = i;
          flag = true;
        }
      }
    }
  }

  return (dist[snk] < INF);
}

int mcmf(int &fcost) {
  int netflow, bot, u;
  netflow = fcost = 0;

  while(bellman()) {
    bot = INF;
    for(u = pre[snk]; u >= 0; u = pre[from[u]]) bot =
      min(bot, cap[u]);

    for(u = pre[snk]; u >= 0; u = pre[from[u]]) {
      cap[u] -= bot;
      cap[u^1] += bot;
      fcost += bot * cost[u];
    }

    netflow += bot;
  }

  return netflow;
}

int main() {
  scanf("%d%d%d", &n, &s, &e);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &d[i]);

  init(n, n+1, n+2);
  addEdge(n, s, 1, 0);
  addEdge(e, n+1, 1, 0);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) if (i != j)
      addEdge(i, j, 1, abs(x[i]-x[j])+(j<i?c[i]+b[j]:d[i]+a[j]));

  int costt;
  db(mcmf(costt));
  printf("%d\n", costt);

  return 0;
}
