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

int n, q, a[N], b[N], lz[N], l, r;

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < q; ++i) scanf("%d%d", &l, &r), lz[l-1]++, lz[r]--;

  int sum = 0;
  for (int i = 0; i < n; ++i) sum += lz[i], b[i]=sum;

  sort(b,b+n); sort(a,a+n);

  ll ans = 0;
  for (int i = 0; i < n; ++i) ans += 1ll*a[i]*b[i];

  printf("%lld\n", ans);
  return 0;
}
