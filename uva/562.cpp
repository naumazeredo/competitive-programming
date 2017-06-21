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

int t, n, a[N], tot, ans;
int dp[100000];

int main() {
  scanf("%d", &t);
  while (t--) {
    cl(dp,0);
    scanf("%d", &n);
    tot = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), tot+=a[i];

    dp[0] = 1;
    for (int i = 0; i < n; ++i) for (int j = tot; j >= 0; --j)
      if (dp[j]) dp[j+a[i]]=1;

    ans = tot;
    for (int i = 0; i <= tot; ++i) if (dp[i]) ans = min(ans, abs(tot-2*i));
    printf("%d\n", ans);
  }
  return 0;
}
