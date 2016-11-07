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

int n, s, d;
set<pii> b;

int main() {
  scanf("%d", &n);
  b.insert({ 1, INF });

  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &s, &d);

    int ok = 0;
    for (auto x : b) {
      if (x.st <= s and x.nd >= s+d-1) {
        b.erase(x);
        if (s > x.st) b.insert({ x.st, s-1 });
        if (s+d-1 < x.nd) b.insert({ s+d, x.nd });
        ok = 1;
        break;
      }
    }

    if (ok) printf("%d %d\n", s, s+d-1);
    else {
      for (auto x : b) {
        if (x.nd - x.st + 1 >= d) {
          b.erase(x);
          if (x.st + d - 1 < x.nd) b.insert({ x.st + d, x.nd });
          printf("%d %d\n", x.st, x.st + d - 1);
          break;
        }
      }
    }
  }

  return 0;
}
