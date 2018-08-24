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
const int N = 2e3+5;

int t, k, n, a[N], b[N], vis[N], ans[N];
vector<int> adj[N];

void pre(int u, vector<int>& v) {
  v.pb(u);
  if (a[u]) pre(a[u], v);
  if (b[u]) pre(b[u], v);
}

void pos(int u, vector<int>& v) {
  if (a[u]) pos(a[u], v);
  if (b[u]) pos(b[u], v);
  v.pb(u);
}

void dfs(int u, int c) {
  vis[u] = 1;
  ans[u] = c;
  for (int v : adj[u]) if (!vis[v]) dfs(v, c);
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i], &b[i]);
      adj[i].clear();
      vis[i] = 0;
    }

    vector<int> l, r;
    pre(1, l); pos(1, r);

    for (int i = 0; i < (int)l.size(); i++) {
      adj[l[i]].pb(r[i]);
      adj[r[i]].pb(l[i]);
    }

    int kk = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
      kk = min(kk+1, k);
      dfs(i, kk);
    }

    printf("Case #%d: ", tt);
    if (kk < k) printf("Impossible\n");
    else for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i==n]);
  }
  return 0;
}
