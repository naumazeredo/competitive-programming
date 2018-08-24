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
const int N = 1e2+5;

const int p[4] = { 0b0111, 0b1011, 0b1101, 0b1110 };

int n;
char g[2][N];
int dp[N][4];

int fit(int i, int m) { return !(p[i]&m); }

int go(int x, int m) {
  if (x == n) return 0;

  if (~dp[x][m]) return dp[x][m];
  dp[x][m] = 0;

  int l = m + (g[0][x]<<2) + (g[1][x]<<3);
  dp[x][m] = go(x+1, l>>2);

  for (int i = 0; i < 4; i++) if (fit(i, l))
    dp[x][m] = max(dp[x][m], 1+go(x+1, (l|p[i])>>2));
  return dp[x][m];
}

int main() {
  scanf("%s%s", g[0], g[1]);
  n = strlen(g[0]);
  for (int j = 0; j < 2; j++) for (int i = 0; i < n; i++) g[j][i] = (g[j][i]=='X');

  cl(dp, -1);
  printf("%d\n", go(1,g[0][0]+(g[1][0]<<1)));
  return 0;
}
