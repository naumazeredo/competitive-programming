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
const int N = 3e5+5;

int n, m;
ll ans[N], add[N];

vector<int> adj[N];
vector<pii> qs[N];

void dfs(int u, int p, int h, ll acc) {
  for (auto q : qs[u]) {
    int d = q.st, x = q.nd;
    add[h] += x;
    add[min(n, h + d + 1)] -= x;
  }

  acc += add[h];
  ans[u] = acc;

  for (int v : adj[u]) if (v != p) dfs(v, u, h+1, acc);

  for (auto q : qs[u]) {
    int d = q.st, x = q.nd;
    add[h] -= x;
    add[min(n, h + d + 1)] += x;
  }
}

int main() {
  scanf("%d", &n);
  for (int u, v, i = 0; i < n-1; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  scanf("%d", &m);
  for (int v, d, x, i = 0; i < m; i++) {
    scanf("%d%d%d", &v, &d, &x);
    qs[v].push_back({ d, x });
  }

  dfs(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
