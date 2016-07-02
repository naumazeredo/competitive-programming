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

const ld EPS = 1e-6, PI = acos(-1);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, m, k, mtc[N][N], dp[N][N][11], a;
char s[N], t[N];

int main() {
  scanf("%d%d%d%s%s", &n, &m, &k, s, t);
  for (int i = n-1; i >= 0; --i) for (int j = m-1; j >= 0; --j)
    mtc[i][j] = s[i]==t[j]?1+mtc[i+1][j+1]:0;

  for (int x = 1; x <= k; ++x) for (int i = n-1; i >= 0; --i) for (int j = m-1; j >= 0; --j)
    a = mtc[i][j], dp[i][j][x] = max(a+dp[i+a][j+a][x-1], max(dp[i+1][j][x], dp[i][j+1][x]));

  printf("%d\n", dp[0][0][k]);

  return 0;
}
