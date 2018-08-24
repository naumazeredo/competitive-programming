// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

// 0 : right
// 1 : down
// 2 : left
// 3 : up

int n, m, g[N][N], dp[4][N][N], r[N][N], pre[2][N][N];
char c;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf(" %c", &c),
      g[i][j] = c=='*';

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp[0][i][j] = g[i][j] ? 1 + dp[0][i][j-1] : 0,
      dp[1][i][j] = g[i][j] ? 1 + dp[1][i-1][j] : 0;

  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
      dp[2][i][j] = g[i][j] ? 1 + dp[2][i][j+1] : 0,
      dp[3][i][j] = g[i][j] ? 1 + dp[3][i+1][j] : 0;

  vector<piii> ans;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (g[i][j]) {
    int lo = 0;
    int hi = min({ abs(i-1), abs(n-i), abs(j-1), abs(m-j) });

    while (lo < hi) {
      int md = (lo+hi+1)/2;

      int ok = 1;
      for (int k = 0; k < 4; k++)
        if (dp[k][i][j] - 1 < md)
          ok = 0;

      if (ok) lo = md;
      else hi = md-1;
    }

    if (lo) ans.push_back({ { i, j }, lo });
  }

  for (auto x : ans) {
    pre[0][x.st.st][x.st.nd-x.nd]++;
    pre[0][x.st.st][x.st.nd+x.nd+1]--;

    pre[1][x.st.st-x.nd][x.st.nd]++;
    pre[1][x.st.st+x.nd+1][x.st.nd]--;
  }

  /*
  printf("\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d", pre[0][i][j]);
    printf("\n");
  }

  printf("\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d", pre[1][i][j]);
    printf("\n");
  }
  */

  int ok = 1;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
    pre[0][i][j] += pre[0][i][j-1];
    pre[1][i][j] += pre[1][i-1][j];
    r[i][j] = !!(pre[0][i][j] + pre[1][i][j]);
    if (r[i][j] != g[i][j]) ok = 0;
  }

  /*
  printf("\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d", pre[0][i][j]);
    printf("\n");
  }

  printf("\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d", pre[1][i][j]);
    printf("\n");
  }

  printf("\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d", r[i][j]);
    printf("\n");
  }
  */

  if (!ok) return !printf("-1\n");

  printf("%d\n", (int)ans.size());
  for (auto x : ans) printf("%d %d %d\n", x.st.st, x.st.nd, x.nd);

  return 0;
}
