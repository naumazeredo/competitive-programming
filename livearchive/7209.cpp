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
typedef pair<ld, int> pdi;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, m, x, y, a, b;
vi adj[N], adja[N], adjb[N];
ld dist[N];

ld dijkstra(ld t) {
  for (int i = 1; i <= n; ++i) dist[i] = -1;

  priority_queue<pdi> pq;
  pq.push(mp(0, 1));
  dist[1] = 0;

  while (pq.size()) {
    ld d = -pq.top().st;
    int u = pq.top().nd; pq.pop();

    if (u == n) break;
    if (d > dist[u] + EPS) continue;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
      int v = adj[u][i], a = adja[u][i], b = adjb[u][i];
      ld w = a * t + b;
      if (dist[v]<0 or dist[v] > dist[u] + w + EPS)
        dist[v] = dist[u] + w,
        pq.push(mp(-dist[v], v));
    }
  }

  return dist[n];
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; ++i)
      adj[i].clear(), adja[i].clear(), adjb[i].clear();

    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d%d", &x, &y, &a, &b);
      adj[x].pb(y); adja[x].pb(a); adjb[x].pb(b);
      adj[y].pb(x); adja[y].pb(a); adjb[y].pb(b);
    }

    ld lo = 0, hi = 24*60;
    for (int i = 0; i < 200; ++i) {
      ld p1 = (2*lo+hi)/3;
      ld p2 = (lo+2*hi)/3;
      ld t1 = dijkstra(p1), t2 = dijkstra(p2);
      if (t1 < t2 - EPS) lo = p1;
      else hi = p2;
    }

    printf("%.5Lf\n", dijkstra((lo+hi)/2));
  }
  return 0;
}
