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

int n, a[N], t[N];
vi s;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  t[0] = -1;
  s.pb(0);
  for (int i = 1; i < n; ++i) {
    if (a[s.back()]>a[i]) {
      t[i] = 0; s.pb(i);
    } else {
      while (s.size() and a[s.back()]<=a[i])
        t[i] = max(t[i], t[s.back()]+1), s.pop_back();
      if (s.empty()) t[i] = -1;
      s.pb(i);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) ans = max(ans, 1+t[i]);
  printf("%d\n", ans);

  return 0;
}
