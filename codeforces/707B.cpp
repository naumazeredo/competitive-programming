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

int n, m, k, a, b, c, st[N];
vi adj[N], w[N];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    adj[a].pb(b), w[a].pb(c);
    adj[b].pb(a), w[b].pb(c);
  }

  for (int i = 0; i < k; ++i) scanf("%d", &a), st[a]=1;

  int ans = INF;
  for (int i = 1; i <= n; ++i) if (st[i]) {
    for (int j = 0; j < adj[i].size(); ++j) {
      int v = adj[i][j], c = w[i][j];
      if (!st[v]) ans = min(ans, c);
    }
  }

  printf("%d\n", ans==INF?-1:ans);

  return 0;
}
