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
const int N = 2e5+5;

int n, k;
vector<pii> e;
int h[2], d[N];

int main() {
  scanf("%d%d", &n, &k);
  int nn = 1, kk = 0;

  for (; kk < k; kk++) e.pb({ 1, ++nn }), d[nn] = 1;
  h[0] = 1; h[1] = 1;
  while (nn < n) nn++, e.pb({ nn-k, nn }), d[nn] = d[nn-k] + 1, h[1] = h[0], h[0] = d[nn];
  printf("%d\n", h[0] + h[1]);
  for (auto x : e) printf("%d %d\n", x.st, x.nd);

  return 0;
}
