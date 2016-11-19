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

int n, m, a, b, x, y, t[N], o[N], sz;
vi adj[N];

int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    adj[x].pb(y), adj[y].pb(x);
    t[x]++, t[y]++;
  }

  queue<int> q;
  sz = n;

  while (1) {
    for (int i = 1; i <= n; ++i) if (!o[i] and (t[i] < a or sz-1-t[i] < b)) q.push(i), o[i]=1;

    if (q.empty()) break;

    while (q.size()) {
      int u = q.front(); q.pop();

      sz--; o[u] = 1;

      for (int v : adj[u]) if (!o[v]) {
        t[v]--;
        if (t[v] == a-1) q.push(v), o[v] = 1;
      }
    }
  }

  printf("%d\n", sz);

  return 0;
}
