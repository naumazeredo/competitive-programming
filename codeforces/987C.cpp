// @subject: 
// @diff: 

#include <bits/stdc++.h>
using namespace std;

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
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e3+5;

int n, s[N], c[N];
int dp[4][N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);

  memset(dp, 63, sizeof dp);
  for (int i = 0; i < n; i++) dp[1][i] = c[i];
  for (int i = 2; i < 4; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k < j; k++)
        if (s[k] < s[j])
          dp[i][j] = min(dp[i][j], dp[i-1][k] + c[j]);

  int ans = INF;
  for (int i = 1; i <= n; i++) ans = min(ans, dp[3][i]);
  if (ans == INF) ans = -1;
  printf("%d\n", ans);

  return 0;
}
