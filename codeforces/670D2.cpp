#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

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
const int N = 1e5+5;

int n, k;
int a[N], b[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

  ll l = 0, r = INT_MAX;
  while (l < r) {
    ll m = (l+r+1)/2;

    ll t = 0;
    for (int i = 0; i < n; ++i) {
      t+=max(m*a[i]-b[i], 0ll);
      if (t > k) break;
    }

    if (t <= k) l = m;
    else r = m-1;
  }

  printf("%lld\n", l);

  return 0;
}
