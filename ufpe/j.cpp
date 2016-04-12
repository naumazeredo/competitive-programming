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

int t, n, c, x;
int g[20][20];

int dp[1000000];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    for (int i = 0; i < 1000000; ++i) dp[i] = -INF;

    scanf("%d", &n);
    c = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &x), c-=x;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &g[i][j]);

    dp[0] = 0;
    for (int i = 1; i < (1<<n); ++i) {
      bitset<20> b(i);
      for (int j = 0; j < n; ++j) if (b[j]) {
        b.reset(j);
        int tot = 0;
        for (int k = 0; k < n; ++k) if (b[k]) tot+=g[j][k];
        dp[i] = max(dp[i], tot+dp[(int)b.to_ulong()]);
        b.set(j);
      }
      //db(b.to_string() _ dp[i]);
    }

    printf("Caso #%d: %d\n", tt, dp[(1<<n)-1]+c);
  }
  return 0;
}
