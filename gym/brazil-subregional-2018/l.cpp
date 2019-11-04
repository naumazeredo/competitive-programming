// @subject: lca
// @diff: easy

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

int n, q, p[N][20], h[N];
vector<int> adj[N];

void dfs(int u) {
  for (int i = 1; i < 20; i++)
    p[u][i] = p[p[u][i-1]][i-1];

  for (int v : adj[u]) if (v != p[u][0]) {
    h[v] = h[u]+1;
    p[v][0] = u;
    dfs(v);
  }
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) if (h[u] - (1<<i) >= h[v]) u = p[u][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
  return p[u][0];
}

int dist(int u, int v) {
  int l = lca(u, v);
  return h[u] + h[v] - 2*h[l] + 1;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int u, v, i = 0; i < n-1; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  for (int u, v, a, b, i = 0; i < q; i++) {
    scanf("%d%d%d%d", &u, &v, &a, &b);
    int d0 = dist(u, v) + dist(a, b);
    int d1 = min(dist(a, u) + dist(b, v), dist(a, v) + dist(b, u));
    printf("%d\n", max((d0-d1)/2+1, 0));
  }

  return 0;
}
