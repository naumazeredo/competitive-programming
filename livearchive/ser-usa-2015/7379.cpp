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

int x[N], y[N], r[N], c[N], vis[N], d[N], ok;
vi adj[N];

int connected(int i, int j) {
  ll dx = x[i]-x[j], dy = y[i]-y[j], rr = r[i]+r[j];
  return dx*dx+dy*dy == rr*rr;
}

void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (vis[v] and c[v] == c[u]) ok = 0;
    if (!vis[v]) d[v] = d[u]+1, c[v] = 1-c[u], dfs(v);
  }
}

int main() {
  int n;
  while(~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) adj[i].clear(), c[i] = -1, vis[i] = 0, d[i] = 0;

    for (int i = 0; i < n; i++) scanf("%d%d%d", &x[i], &y[i], &r[i]);
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) if (connected(i,j)) adj[i].pb(j), adj[j].pb(i);

    ok = 1;
    c[0] = 0; d[0] = 0;
    dfs(0);

    if (!ok) { printf("-1\n"); continue; }
    if (!d[n-1]) { printf("0\n"); continue; }
    printf("%d %d\n", r[n-1]/__gcd(r[0], r[n-1]), ((d[n-1]%2)?-1:1)*r[0]/__gcd(r[0], r[n-1]));
  }
  return 0;
}
