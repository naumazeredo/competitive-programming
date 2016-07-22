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

ll n, m, l[N], c[N], x, y, tl, tc;

int main() {
  scanf("%lld%lld", &n, &m);
  ll ans = 0;
  for (ll i = 0; i < m; ++i) {
    scanf("%lld%lld", &x, &y);

    if (!c[x]) {
      ans += n - tl;
      c[x]++;
      tc++;
    }

    if (!l[y]) {
      ans += n - tc;
      l[y]++;
      tl++;
    }
    printf("%lld ", 1ll*n*n-ans);
  }
  printf("\n");
  return 0;
}
