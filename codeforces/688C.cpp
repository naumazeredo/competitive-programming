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
const int N = 1e5+5;

int n, m, u, v;
vi adj[N];
int c[N];
int vis[N];
int ok;

void dfs(int u) {
  vis[u]=1;
  for (int v : adj[u]) {
    if (!vis[v]) {
      c[v] = c[u]==1?2:1;
      dfs(v);
    } else if (c[v] == c[u]) {
      ok = 0;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }

  ok = 1;
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    c[i] = 1;
    dfs(i);
  }

  if (!ok) return 0*printf("-1\n");
  else {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += c[i]==1;
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++i) if (c[i]==1) printf("%d ", i);
    printf("\n%d\n", n-cnt);
    for (int i = 1; i <= n; ++i) if (c[i]==2) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
