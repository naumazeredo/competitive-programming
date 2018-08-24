// @subject: 
// @diff: 

#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e5+5;

int n, m, vis[N];
vector<pii> adj[N];
vector<int> adj2[N];
int par[N], art[N], low[N], num[N], cnt;

void pont(int u) {
  low[u] = num[u] = ++cnt;
  for (pii x : adj[u]) {
    int v = x.st;
    int k = x.nd;
    if (!num[v]) {
      par[v] = k;

      pont(v);
      if (low[v] > num[u]) {
        adj2[u].push_back(v);
        adj2[v].push_back(u);
      }

      low[u] = min(low[u], low[v]);
    }
    else if (k != par[u]) low[u] = min(low[u], num[v]);
  }
}

int dfs(int u) {
  if (vis[u]) return 0;
  vis[u] = 1;
  int res = 1;
  for (int v : adj2[u])
    res += dfs(v);
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int u, v, i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back({ v, i });
    adj[v].push_back({ u, i });
  }

  pont(1);
  ll ans = 1ll*n*(n-1)/2;
  for (int i = 1; i <= n; i++) if (!vis[i]) {
    ll x = dfs(i);
    ans -= x*(x-1)/2;
  }

  printf("%lld\n", ans);

  return 0;
}
