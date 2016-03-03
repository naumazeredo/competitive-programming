#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int t, n, m, k;
ll a[200][200];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%lld", &a[i][j]);

    for (int i = 0; i < n; ++i) for (int j = 1; j < m; ++j) a[i][j] += a[i][j-1];
    for (int i = 1; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] += a[i-1][j];

    ll ma = 0, mc = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      for (int x = i; x < n; ++x) for (int y = j; y < m; ++y) {
        ll c = a[x][y]-(i>0?a[i-1][y]:0)-(j>0?a[x][j-1]:0)+(i>0&&j>0?a[i-1][j-1]:0);
        ll ar = abs(y-j+1)*abs(x-i+1);

        if (ar > ma and c <= k) ma = ar, mc = c;
        else if (ar == ma and c < mc) mc = c;
      }
    }

    printf("Case #%d: %lld %lld\n", tt, ma, mc);
  }
  return 0;
}
