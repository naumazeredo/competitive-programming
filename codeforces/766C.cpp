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
const int N = 1e3+5;

int n, a[30], b[30], dp[N], ml, g;
char s[N];
ll dps[N], x[N];

int main() {
  scanf("%d %s", &n, s);
  for (int i = 0; i < 26; ++i) scanf("%d", &a[i]);

  x[1] = 1;
  for (int i = 2; i < n; ++i) x[i] = (x[i-1]*2)%MOD;
  for (int i = 0; i < n; ++i) s[i] -= 'a';

  cl(dp,63);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) b[j] = 0;

    int j = i;
    while (j < n) {
      b[s[j]]=1;
      int ok = 1;
      for (int k = 0; k < 26; ++k) if (b[k] and a[k] < j-i+1) ok = 0;
      if (!ok) break;

      if (!i) dp[j] = 1;
      else dp[j] = min(dp[j], dp[i-1]+1);

      if (!i) dps[j] = (dps[j] + 1)%MOD;
      else dps[j] = (dps[j] + dps[i-1])%MOD;

      j++;
    }
    ml = max(ml, j-i);
    g = j;
  }

  printf("%lld\n%d\n%d\n", dps[n-1], ml, dp[n-1]);

  return 0;
}
