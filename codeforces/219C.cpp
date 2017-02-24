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
const int N = 5e5+5;

int n, k, dp[N][30], dpb[N][30], v[N];
char c;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf(" %c", &c), v[i] = c-'A';

  cl(dp, INF);
  for (int i = 0; i < k; ++i) dp[0][i] = 1;
  dp[0][v[0]] = 0;

  for (int i = 1; i < n; ++i)
    for (int j = 0; j < k; ++j) {
      if (j != 0)
        dp[i][j] = dp[i-1][0] + (v[i]!=j),
        dpb[i][j] = 0;
      else
        dp[i][j] = dp[i-1][1] + (v[i]!=j),
        dpb[i][j] = 1;

      for (int l = 1; l < k; ++l) if (j != l)
        if (dp[i][j] > dp[i-1][l] + (v[i]!=j))
          dp[i][j] = dp[i-1][l] + (v[i]!=j),
          dpb[i][j] = l;
    }

  /*
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < k; ++j)
      db(i _ j _ dp[i][j] _ dpb[i][j]);
      */

  int ans = INF, ansb;
  for (int i = 0; i < k; ++i) if (ans > dp[n-1][i])
    ans = dp[n-1][i], ansb = i;

  printf("%d\n", ans);
  stack<char> s;
  for (int i = n-1; i >= 0; --i)
    s.push(ansb+'A'), ansb = dpb[i][ansb];

  while (s.size()) printf("%c", s.top()), s.pop();
  printf("\n");
  return 0;
}
