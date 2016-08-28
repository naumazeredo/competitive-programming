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

int t, a[4], b[4];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    scanf("%d%d%d%d", &a[0], &a[1], &a[3], &a[2]);
    scanf("%d%d%d%d", &b[0], &b[1], &b[3], &b[2]);

    int ok = 0;
    for (int i = 0; i < 4; ++i) {
      int x = 1;
      for (int j = 0; j < 4; ++j) if (a[j] != b[(i+j)%4]) x = 0;
      ok = max(ok, x);
    }

    printf("Case #%d: %s\n", tt, ok?"POSSIBLE":"IMPOSSIBLE");
  }

  return 0;
}
