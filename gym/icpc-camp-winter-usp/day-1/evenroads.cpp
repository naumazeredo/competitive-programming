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

int n, m, a, b, c, d[N];
vi adj[N], adjw[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    adj[a].pb(b+n); adjw[a].pb(c);
    adj[b].pb(a+n); adjw[b].pb(c);

    adj[a+n].pb(b); adjw[a+n].pb(c);
    adj[b+n].pb(a); adjw[b+n].pb(c);
  }

  cl(d,63);
  priority_queue<pii> q;
  q.push({0, 1}); d[1] = 0;
  while (q.size()) {
    int u = q.top().nd;
    int ud = -q.top().st;
    q.pop();

    if (d[u] < ud) continue;
    if (u == n) break;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i], w = adjw[u][i];
      if (d[v] > d[u] + w)
        d[v] = d[u]+w, q.push({ -d[v], v });
    }
  }

  printf("%d\n", d[n]==INF?-1:d[n]);

  return 0;
}
