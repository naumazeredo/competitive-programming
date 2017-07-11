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

char a[N], b[N];
int dp[N][N];

int main() {
  while (gets(a) and gets(b)) {
    int n = strlen(a), m = strlen(b);
    cl(dp,0);

    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if (a[i-1]==b[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
    }

    printf("%d\n", dp[n][m]);
  }
  return 0;
}
