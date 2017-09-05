#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

struct stat { ll a, b, id; };

int n, a[N], da[N], b[N], db[N], best[N][2];
vector<stat> st[2];
ld tb[N][2], te[N][2], t;

int nh;
stat hull[N];

ld evalx(stat x, stat y) { return (y.a - x.a)/(ld)(x.b - y.b); }

bool check(stat x, stat y, stat z) { return (x.a - y.a) * (z.b - x.b) < (x.a - z.a) * (y.b - x.b); }
void update(stat l) {
  if (nh == 1 and hull[nh-1].a == l.a) nh--; // ordered updates, ignore previous starting lines with same y(0)
  if (nh and hull[nh-1].b >= l.b) return;    // ordered updates, ignore new parallel lines
  while (nh >= 2 and !check(hull[nh-2], hull[nh-1], l)) nh--;
  hull[nh++] = l;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &a[i], &da[i], &b[i], &db[i]);
    st[0].pb({ a[i], da[i], i });
    st[1].pb({ -b[i], -db[i], i });

    te[i][0] = 1e50;
    te[i][1] = 1e50;
  }

  for (int j = 0; j < 2; j++) {
    sort(st[j].begin(), st[j].end(), [](stat x, stat y) { return x.a == y.a ? x.b < y.b : x.a > y.a; });
    for (auto x : st[j]) db(x.id _ x.a _ x.b);

    nh = 0;
    for (int i = 0; i < n; i++) update(st[j][i]);
    for (int i = 0; i < nh; i++) db(hull[i].id _ hull[i].a _ hull[i].b);

    int l = hull[0].id;
    tb[l][j] = 0;
    best[l][j] = 1;
    for (int i = 1; i < nh; i++) {
      ld t = evalx(hull[i], hull[i-1]);
      te[l][j] = t;

      l = hull[i].id;
      tb[l][j] = t;
      best[l][j] = 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!best[i][0] or !best[i][1]) continue;
    ld ib = max(tb[i][0], tb[i][1]);
    ld ie = min(te[i][0], te[i][1]);
    if (ie - ib > EPS) ans++;
  }

  printf("%d\n", ans);

  return 0;
}
