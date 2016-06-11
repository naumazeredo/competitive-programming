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
const int N = 20;

int t, n, d[N][1<<N], dp[1<<N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &d[i][1<<j]);
    for (int i = 0; i < n; ++i) for (int j = 1; j < (1<<n); ++j)
      d[i][j] = d[i][j-(j&-j)]+d[i][j&-j];

    cl(dp,0);
    dp[(1<<n)-1]=1;
    for (int i = (1<<n)-1; i > 0; --i) {
      if (!dp[i]) continue;
      for (int j = 0; j < n; ++j) if ((1<<j)&i and d[j][i]>0) dp[i-(1<<j)]=1;
    }

    vi ans;
    for (int i = 0; i < n; ++i) if (dp[1<<i]) ans.pb(i+1);
    if (ans.size()) for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], i==ans.size()-1?'\n':' ');
    else printf("0\n");
  }
  return 0;
}
