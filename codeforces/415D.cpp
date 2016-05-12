#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

#define fi first
#define se second

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n, k;
vector<int> d[2005];
ll dp[2005][2005];

ll mod = 1e9+7;

int main() {
  scanf("%d%d", &n, &k);

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      if (i%j==0)
        d[i].push_back(j);

  for (int i = 1; i <= n; ++i) dp[1][i] = 1;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 0; k < d[j].size(); ++k)
        dp[i][j] = (dp[i][j]+dp[i-1][d[j][k]])%mod;

  ll s = 0;
  for (int i = 1; i <= n; ++i) s=(s+dp[k][i])%mod;
  printf("%lld\n", s);
  return 0;
}
