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

int n, m, k, f[N], a, b, e[N];
vi adj[N];

int main() {
  while (~scanf("%d%d%d", &n, &m, &k)) {
    for (int i = 1; i <= n; ++i) adj[i].clear(), f[i] = 0, e[i] = 0;

    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &a, &b);
      adj[a].pb(b), adj[b].pb(a);
      f[a]++, f[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) if (f[i] < k) q.push(i), e[i]=1;

    while (q.size()) {
      int u = q.front(); q.pop();
      for (int v : adj[u]) if (!e[v] and --f[v] < k)
        q.push(v), e[v]=1;
    }

    vi ans;
    for (int i = 1; i <= n; ++i) if (!e[i]) ans.pb(i);

    if (ans.size())
      for (int i = 0; i < (int)ans.size(); ++i)
        printf("%d%c", ans[i], i<(int)ans.size()-1?' ':'\n');
    else printf("0\n");
  }
  return 0;
}
