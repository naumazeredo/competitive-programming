#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
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
const int N = 2e5+5;

int n, a, b, inc[N], np[N], vis[N], h[N];
vi adj[N];
map<int, int> mp[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d%d", &a, &b);
    adj[a].pb(b); adj[b].pb(a);
    inc[a]++, inc[b]++;
  }

  // already a path
  /*
  int ok = 1;
  for (int i = 1; i <= n and ok; ++i) if (inc[i]>2) ok = 0;
  if (ok) return 0*printf("%d\n", n-1);
  */

  // not a path
  queue<int> q;
  for (int i = 1; i <= n; ++i) if (inc[i] < 2) q.push(i), mp[i][0]=1;

  int ans = 0;
  while (q.size()) {
    int u = q.front(); q.pop();
    vis[u] = 1;

    // last
    if (!inc[u]) {
      if (np[u]) break;
      if (mp[u].size() > 2) break;
      if (mp[u].size() == 2) {
        for (auto x : mp[u]) ans += x.st;
        while (ans%2==0) ans/=2;
        return 0*printf("%d\n", ans);
      }

      ans = (mp[u].begin())->st;
      while (ans%2==0) ans/=2;
      return 0*printf("%d\n", ans);
    }

    if (!np[u]) {
      if (mp[u].size() > 1) np[u] = 1;
      else h[u] = (mp[u].begin())->st;
    }

    for (int v : adj[u]) if (!vis[v]) {
      np[v] |= np[u];
      mp[v][h[u]+1]++;

      inc[v]--;
      if (inc[v] == 1) q.push(v);
    }
  }

  printf("-1\n");
  return 0;
}
