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

int n, m, e[N], ans, a, b, c;
vector<pii> s[N]; // c, s

int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i <= m; ++i) s[i].clear();

    for (int i = 1; i <= n; ++i) scanf("%d", &e[i]), e[i]+=e[i-1];
    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      s[a].pb({b, c});
    }

    int p = 1;
    priority_queue<piii> pq; // c, s, p
    for (auto v : s[p])
      pq.push({ -v.nd, { v.st, p } });

    ans = 0;
    while (pq.size() and p <= n) {
      int c = -pq.top().st;
      int v = pq.top().nd.st;
      int x = pq.top().nd.nd;
      pq.pop();

      while (p <= n and e[p] - e[x-1] <= v) {
        ans = c;
        p++;
        for (auto v : s[p])
          pq.push({ -(c+v.nd), { v.st, p } });
      }
    }

    printf("%d\n", p>n?ans:-1);
  }
  return 0;
}
