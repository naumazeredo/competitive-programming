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

int n, m, k, s, t;
vector<piii> adj[N];
vector<int> v;

int vis[N], cur;

void dfs(int u) {
  if (vis[u] == cur) return;
  vis[u] = cur;

  for (auto p : adj[u]) if (p.nd.st <= cur and cur <= p.nd.nd) dfs(p.st);
}

int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
  for (int a, b, c, d, i = 0; i < m; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    adj[a].push_back({ b, { c, d } });
    v.push_back(c);
    v.push_back(d);
    if (c > 1) v.push_back(c-1);
    if (d < k) v.push_back(d+1);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int ans = 0, l = -1;
  for (int x : v) {
    cur = x;
    dfs(s);
    if (vis[t] == x) {
      ans += (~l) ? x - l : 1;
      l = x;
    } else {
      ans += (~l) ? x-1 - l : 0;
      l = -1;
    }
  }
  printf("%d\n", ans);

  return 0;
}
