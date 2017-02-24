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

int n, t[N];
int dp[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &t[i]);

  int ans = 20;
  dp[0] = 20;
  printf("20\n");
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i-1] + 20;
    int p = lower_bound(t, t+i, t[i]-89)-t;
    dp[i] = min(dp[i], 50 + (p?dp[p-1]:0));

    p = lower_bound(t, t+i, t[i]-1439)-t;
    dp[i] = min(dp[i], 120 + (p?dp[p-1]:0));
    printf("%d\n", dp[i]-ans);
    ans = dp[i];
  }

  return 0;
}
