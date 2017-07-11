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
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, m, d, p[N], s[N], g[N], a, b, vis[N], cc;
vi adj[N];
vi dr[N], drc[N];

void dfs(int u) {
  vis[u] = 1;
  for (auto x : dr[u]) drc[cc].pb(x);
  for (auto v : adj[u]) if (!vis[v]) dfs(v);
}

int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    adj[a].pb(b); adj[b].pb(a);
  }

  for (int i = 0; i < d; i++) {
    scanf("%d%d%d", &p[i], &s[i], &g[i]);
    dr[p[i]].pb(i);
  }

  for (int i = 0; i < n; i++)
    if (!vis[i]) dfs(i), cc++;

  int ans = 0;
  for (int i = 0; i < cc; i++) {
    int lo = 0, hi = 1e6;
    while (lo < hi) {
      int mid = (lo+hi)/2;

      ll ok = 1, rem = mid;
      for (auto j : drc[i]) if (g[j] >= mid) {
        rem -= s[j];
        if (rem < 0) { ok = 0; break; }
      }

      if (ok) hi = mid;
      else lo = mid+1;
    }
    ans += lo;
  }

  printf("%d\n", ans);

  return 0;
}
