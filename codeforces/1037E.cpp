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
const int N = 2e5+5;

int n, m, k, g[N], inc[N], ans[N], u[N], v[N];
set<int> adj[N];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u[i], &v[i]);
    adj[u[i]].insert(v[i]); inc[u[i]]++;
    adj[v[i]].insert(u[i]); inc[v[i]]++;
  }

  queue<int> q;
  for (int j = m; j >= 0; j--) {
    //db(j);
    if (j == m) {
      ans[j] = n;
      fill(g, g+n+1, 1);
      for (int i = 1; i <= n; i++) if (inc[i] < k) q.push(i);
    } else {
      if (adj[u[j]].count(v[j])) {
        //db(u[j] _ v[j]);
        //db(g[u[j]] _ inc[u[j]]);
        //db(g[v[j]] _ inc[v[j]]);

        if (g[u[j]] and inc[u[j]] == k) q.push(u[j]);
        if (g[v[j]] and inc[v[j]] == k) q.push(v[j]);

        adj[u[j]].erase(v[j]); inc[u[j]]--;
        adj[v[j]].erase(u[j]); inc[v[j]]--;
      }

      ans[j] = ans[j+1];
    }

    while (q.size()) {
      int u = q.front(); q.pop();
      //db(u);
      g[u] = 0;
      ans[j]--;
      inc[u] = 0;

      for (int v : adj[u]) {
        if (g[v] and inc[v] == k) q.push(v);
        inc[v]--;
        adj[v].erase(u);
      }
      adj[u].clear();
    }

    /*
    for (int i = 1; i <= n; i++) printf("%d ", inc[i]);
    printf("\n");
    */
  }

  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);

  return 0;
}
