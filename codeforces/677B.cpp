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

int n, h, k, a[N];

int main() {
  scanf("%d%d%d", &n, &h, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  ll tot = 0, ans = 0, i = 0;
  while (i < n) {
    if (tot+a[i]>h) {
      tot = 0;
      ans++;
    }
    while (i<n and tot+a[i]<=h) tot+=a[i++];
    ans += tot/k;
    tot %= k;
  }

  ans += !!tot;
  printf("%lld\n", ans);

  return 0;
}
