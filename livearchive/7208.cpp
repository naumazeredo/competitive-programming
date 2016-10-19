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
const ll M = 2*MOD;

struct st {
  int type;
  int x, y0, y1;
};
vector<st> vec;

map<ll, int> bit;

void add(ll p, int v) { for (; p <= M; p+=p&-p) bit[p]+=v; }
int query(ll p) {
  int sum = 0;
  for (; p; p-=p&-p) sum+=bit[p];
  return sum;
}

int p, v, px[N], py[N], fx[N], fy[N];

int main() {
  while (~scanf("%d%d", &p, &v)) {
    bit.clear();
    vec.clear();
    for (int i = 1; i <= p; ++i) scanf("%d%d", &px[i], &py[i]), vec.pb({ 0, px[i], i, 0 });

    scanf("%d%d", &fx[0], &fy[0]);
    for (int i = 1; i < v; ++i) {
      scanf("%d%d", &fx[i], &fy[i]);
      if (fx[i] == fx[i-1]) vec.pb({ 1, fx[i], fy[i-1], fy[i] });
    }

    if (fx[0] == fx[v-1]) vec.pb({ 1, fx[0], fy[v-1], fy[0] });

    sort(vec.begin(), vec.end(), [](st a, st b) {
      if (a.x == b.x) return a.type < b.type;
      return a.x < b.x;
    });

    ll ans = 0;
    for (auto k : vec) {
      if (k.type) {
        add(k.y0+MOD, 1);
        add(k.y1+MOD, -1);
      } else if (!query(py[k.y0]+MOD)) {
        ans += k.y0;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
