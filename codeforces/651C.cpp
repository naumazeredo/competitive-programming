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
const int N = 2e5+5;

int n, x, y;
map<int, ll> c, l;
map<pii, ll> p;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &x, &y), c[x]++, l[y]++, p[mp(x,y)]++;

  ll ans = 0;
  for (auto it = c.begin(); it != c.end(); ++it) ans+=1ll*(it->nd)*(it->nd-1)/2;
  for (auto it = l.begin(); it != l.end(); ++it) ans+=1ll*(it->nd)*(it->nd-1)/2;
  for (auto it = p.begin(); it != p.end(); ++it) ans-=1ll*(it->nd)*(it->nd-1)/2;

  printf("%lld\n", ans);
  return 0;
}
