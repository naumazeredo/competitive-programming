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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e3+5;

int n, k;
ll p, a[N], b[N];

ll solv(int l) {
  ll res = 0;
  for (int i = 0; i < n; i++) res = max(res, abs(a[i]-b[i+l])+abs(b[i+l]-p));
  return res;
}

int main() {
  scanf("%d%d%lld", &n, &k, &p);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < k; i++) scanf("%lld", &b[i]);
  sort(a,a+n); sort(b,b+k);

  ll ans = LINF;
  for (int i = 0; i <= k-n; i++) ans = min(ans, solv(i));
  printf("%lld\n", ans);

  return 0;
}
