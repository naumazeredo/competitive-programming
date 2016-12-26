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

int x[3], y[3];
set<pii> s;

int main() {
  for (int i = 0; i < 3; ++i) scanf("%d %d", &x[i], &y[i]);

  s.insert({ x[0] + (x[1]-x[2]), y[0] + (y[1] - y[2]) });
  s.insert({ x[0] + (x[2]-x[1]), y[0] + (y[2] - y[1]) });
  s.insert({ x[1] + (x[0]-x[2]), y[1] + (y[0] - y[2]) });
  s.insert({ x[1] + (x[2]-x[0]), y[1] + (y[2] - y[0]) });
  s.insert({ x[2] + (x[0]-x[1]), y[2] + (y[0] - y[1]) });
  s.insert({ x[2] + (x[1]-x[0]), y[2] + (y[1] - y[0]) });

  set<pii> ans;
  for (pii v : s) {
    int ok = 1;
    for (int i = 0; i < 3; ++i) if (v.st == x[i] and v.nd == y[i]) ok = 0;
    if (ok) ans.insert(v);
  }

  printf("%d\n", (int)ans.size());
  for (pii x : ans) printf("%d %d\n", x.st, x.nd);

  return 0;
}
