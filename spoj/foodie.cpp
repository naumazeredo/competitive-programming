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

int t, n, k, r, a[N], x;
int dp[1000005];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &r);
      a[i] = 0;
      for (int j = 0; j < r; ++j)
        scanf("%d", &x), a[i]+=x;
    }

    cl(dp,0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) for (int j = k; j >= 0; --j)
      if (dp[j] and j+a[i] <= k) dp[j+a[i]] = 1;

    for (int i = k; i >= 0; --i) if (dp[i]) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
