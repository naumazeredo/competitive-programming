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
const int N = 1e3+5;

int n, m, cnt[N], val[N];
vector<int> adj[N];
vector<int> center;

pii dfs(int u, int p, int h) {
  pii ret { h, u };
  for (int v : adj[u]) if (v != p)
    ret = max(ret, dfs(v, u, h+1));
  return ret;
}

int diam() {
  pii ret = dfs(1, 0, 0);
  ret = dfs(ret.nd, 0, 0);
  return ret.st;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int u, v, i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v); cnt[u]++;
    adj[v].push_back(u); cnt[v]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) if (cnt[i] <= 1) q.push(i);

  while (q.size()) {
    int u = q.front(); q.pop();
    if (cnt[u] == 0) center.push_back(u);
    for (int v : adj[u]) if (cnt[v]) {
      cnt[v]--;
      if (cnt[v] == 1) q.push(v), val[v] = val[u]+1;
    }
  }

  sort(center.begin(), center.end(), [](int a, int b){ return val[a] > val[b]; });

  vector<pii> ans;
  for (int i = 1; i < (int)center.size(); i++) {
    ans.push_back({ center[0], center[i] });
    adj[center[0]].push_back(center[i]);
    adj[center[i]].push_back(center[0]);
  }

  printf("%d\n", diam());
  for (auto x : ans) printf("%d %d\n", x.st, x.nd);

  return 0;
}
