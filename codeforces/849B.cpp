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
const int N = 1e3+5;

int n, y[N];
set<pii> s;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &y[i]);
  for (int i = 1; i < n; i++) {
    int dx = i;
    int dy = y[i] - y[0];
    int g = __gcd(dx, dy);
    dx /= g; dy /= g;
    s.insert({dx, dy});
  }

  int ok = 0;
  for (auto x : s) {
    vi v;
    for (int i = 1; i < n; i++) {
      int dx = i;
      int dy = y[i] - y[0];
      int g = __gcd(dx, dy);
      dx /= g; dy /= g;
      if (dx == x.st and dy == x.nd) continue;
      v.pb(i);
    }

    if (v.size() == 0) continue;
    if (v.size() == 1) { ok = 1; break; }

    set<pii> ss;
    for (int i = 1; i < v.size(); i++) {
      int dy = y[v[i]] - y[v[0]];
      int dx = v[i] - v[0];
      int g = __gcd(dx, dy);
      dx /= g; dy /= g;
      ss.insert({dx, dy});
    }

    if (ss.size() > 1) continue;

    pii e = *ss.begin();
    if (e.st == x.st and e.nd == x.nd) { ok = 1; break; }
  }

  if (!ok) {
    set<pii> s;
    for (int i = 2; i < n; i++) {
      int dx = i - 1;
      int dy = y[i] - y[1];
      int g = __gcd(dx, dy);
      dx /= g; dy /= g;
      s.insert({dx, dy});
    }

    if (s.size() == 1) {
      pii x = *s.begin();
      int dx = 1;
      int dy = y[1] - y[0];
      int g = __gcd(dx, dy);
      dx /= g; dy /= g;
      ok = (x.st != dx or x.nd != dy);
    }
  }

  printf("%s\n", ok?"Yes":"No");

  return 0;
}
