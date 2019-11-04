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

int n, k, deg[N], sz[N], vis[N], d[N];
vector<int> adj[N];
int c;

int find_c() {
  int ans = 1;
  for (int i = 1; i <= n; i++) d[i] = deg[i];
  queue<int> q;
  for (int i = 1; i <= n; i++) if (d[i] == 1) q.push(i);
  while (q.size()) {
    int u = q.front(); q.pop();
    ans = u;

    for (int v : adj[u]) {
      d[v]--;
      if (d[v] == 1) q.push(v);
    }
  }
  return ans;
}

void dfs(int u) {
  int ok = 1;

  sz[u] = 1;
  for (int v : adj[u]) if (!sz[v]) {
    dfs(v);
    sz[u] += sz[v];
    if (2*sz[v] >= n) ok = 0;
  }

  if (ok) c = u;
}

int solv(int u, int x) {
  vis[u] = 1;
  if (deg[u] == 1 and x != 0) return 0;
  if (u == c and deg[u] < 3) return 0;
  if (u != c and x != 0 and deg[u] < 4) return 0;

  for (int v : adj[u]) if (!vis[v]) {
    if (!solv(v, x-1)) return 0;
  }
  return 1;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int u, v, i = 0; i < n-1; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v); deg[u]++;
    adj[v].push_back(u); deg[v]++;
  }

  //dfs(1);
  c = find_c();
  printf("%s\n", solv(c, k) ? "Yes" : "No");

  return 0;
}
