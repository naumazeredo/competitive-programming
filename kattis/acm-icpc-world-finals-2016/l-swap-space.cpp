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
const int N = 1e6+5;

int n, a[N], b[N];
vector<pii> g, l;

int main() {
  scanf("%d", &n);
  g.reserve(n);
  l.reserve(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    if (b[i]>=a[i]) g.pb(mp(a[i], -b[i]));
    else l.pb(mp(-b[i], a[i]));
  }

  sort(g.begin(), g.end());
  sort(l.begin(), l.end());
  for (int i = 0; i < l.size(); ++i) g.pb(mp(l[i].nd, l[i].st));

  ll ans = 0;
  ll tot = 0;
  for (pii v : g) {
    v.nd = -v.nd;
    //db(ans _ tot _ v.st _ v.nd);
    if (v.st > tot) {
      ans += v.st - tot;
      tot = v.st;
    }
    tot += v.nd - v.st;
  }

  printf("%lld\n", ans);

  return 0;
}
