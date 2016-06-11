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
const int N = 1e5+5;

int t, n, x, y;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &x, &y);
      int r = 1;
      while (20*20*r*r < x*x+y*y) r++;
      ans += max(0, 11-r);
    }
    printf("%d\n", ans);
  }
  return 0;
}
