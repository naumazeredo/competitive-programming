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
const int N = 1e2+5;

int n, m, dp, x[2], y[2], t;
char g;

int main() {
  scanf("%d%d", &n, &m);
  x[0] = INF; y[0] = INF;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    scanf(" %c", &g);
    if (g == 'B') {
      x[0] = min(x[0], j); x[1] = max(x[1], j);
      y[0] = min(y[0], i); y[1] = max(y[1], i);
      t++;
    }
  }
  //db(x[0] _ x[1] _ y[0] _ y[1] _ t);

  int s;
  if (!t) s = 1;
  else s = 1+max(x[1] - x[0], y[1] - y[0]);

  if (s <= min(n, m)) printf("%d\n", s*s - t);
  else printf("-1\n");

  return 0;
}
