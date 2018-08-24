// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const int N = 1e5+5;

int n, m, x;
vector<pii> adj[N];
ll dist[N], mi;

ll dijkstra(int ma) {
  memset(dist, 63, sizeof dist);
  priority_queue<pii> pq;
  pq.push({ 0, 1 });
  dist[1] = 0;

  while (pq.size()) {
    int d = -pq.top().st;
    int u = pq.top().nd;
    pq.pop();

    if (d > dist[u]) continue;
    for (pii v : adj[u]) if (v.nd <= ma and d + v.nd < dist[v.st]) {
      dist[v.st] = d + v.nd;
      pq.push({ -dist[v.st], v.st });
    }
  }

  return dist[n];
}

bool test(int md) {
  return dijkstra(md) <= (mi * (100+x) + 99) / 100;
}

int main() {
  scanf("%d%d%d", &n, &m, &x);
  for (int a, b, c, i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back({ b, c });
    adj[b].push_back({ a, c });
  }

  mi = dijkstra(INF);
  //db(mi);

  int lo = 1, hi = INF;
  while (lo < hi) {
    int md = (lo+hi)/2;
    //db(lo _ md _ hi _ dijkstra(md) _ test(md));
    if (test(md)) hi = md;
    else lo = md+1;
  }

  printf("%d\n", lo);
  return 0;
}
