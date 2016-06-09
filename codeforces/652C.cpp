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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 3e5+5;

int n, m, p[N], a, b;
vi v[N];
multiset<int> s;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a), p[a]=i;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    if (p[a]>p[b]) swap(a,b);
    v[p[a]].pb(p[b]);
    s.insert(p[b]);
  }
  s.insert(n);

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (*s.begin())-i;
    for (int x : v[i]) s.erase(s.find(x));
  }

  printf("%lld\n", ans);

  return 0;
}
