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
const int N = 2e2+5;

int t, n, m, k, par[N], sz[N], pp[N], a, b, c, ans;

int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }
void unite(int a, int b, int c) {
  if ((a = find(a)) == (b = find(b))) return;
  if (pp[a] and pp[b]) return;
  if (sz[a]<sz[b]) swap(a,b);
  par[b]=a;
  pp[a] |= pp[b];
  ans += c;
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; ++i) par[i]=i, sz[i]=1, pp[i]=0;
    for (int i = 0; i < k; ++i) scanf("%d", &a), pp[a]=1;

    priority_queue<piii> pq;
    for (int i = 0; i < m; ++i) scanf("%d%d%d", &a, &b, &c), pq.push(mp(-c,mp(a,b)));

    ans = 0;
    while (!pq.empty()) {
      c = -pq.top().st;
      a = pq.top().nd.st;
      b = pq.top().nd.nd;
      pq.pop();
      unite(a, b, c);
    }

    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
