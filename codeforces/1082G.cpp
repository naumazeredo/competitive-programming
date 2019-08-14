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

int n, m, a[N], out[N];
vector<pii> adj[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int u, v, w, i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back({ v, w });
    adj[v].push_back({ u, w });
  }

  while (1) {
    ll worst = 0, worst_i = 0;

    for (int i = 1; i <= n; i++) if (!out[i]) {
      ll val = -a[i];
      for (auto x : adj[i]) if (!out[x.st]) val += x.nd;
      if (val < worst) worst = val, worst_i = i;
    }

    if (worst_i == 0) break;

    out[worst_i] = 1;
  }

  ll ans = 0, sub = 0;
  for (int i = 1; i <= n; i++) if (!out[i]) {
    sub += a[i];
    for (auto x : adj[i]) if (!out[x.st])
      ans += x.nd;
  }

  ans /= 2;
  ans -= sub;

  printf("%lld\n", ans);

  return 0;
}
