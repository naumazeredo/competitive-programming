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

int n, m, a, b, x, y, t[N], o[N];
vi adj[N];

int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    adj[x].pb(y), adj[y].pb(x);
    t[x]++, t[y]++;
  }

  set<pii> s;
  for (int i = 1; i <= n; ++i) s.insert({ t[i], i });

  while (s.size()) {
    int ok = 1;

    vector<pii> vec;
    vec.pb(*s.begin());
    if (s.size() > 1) vec.pb(*s.rbegin());

    for (auto u : vec) if (u.st < a or (int)(s.size() - 1 - u.st) < b) {
      s.erase(u);
      o[u.nd] = 1;
      for (int v : adj[u.nd]) if (!o[v]) {
        s.erase({ t[v], v });
        t[v]--;
        s.insert({ t[v], v });
      }

      ok = 0;
    }

    if (ok) break;
  }

  printf("%d\n", (int)s.size());

  return 0;
}
