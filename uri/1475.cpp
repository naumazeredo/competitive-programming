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

int n, c, a, b, x;
int dp[2][2222];
vi f[2];

int go(int x, int i) {
  if (x < 0) return 0;
  if (dp[i][x]) return dp[i][x];
  return dp[i][x] = min(go(lower_bound(f[i].begin(), f[i].end(), f[i][x]-a)-f[i].begin()-1, i)+a,
                        go(lower_bound(f[i].begin(), f[i].end(), f[i][x]-b)-f[i].begin()-1, i)+b);
}

int main() {
  while (~scanf("%d%d%d%d", &n, &c, &a, &b)) {
    f[0].clear(); f[1].clear();

    for (int i = 0; i < n; ++i) scanf("%d", &x), f[0].pb(x);

    f[1].pb(f[0][n-1]);
    for (int i = 1; i < n; ++i) f[1].pb(f[0][i-1]+c);

    memset(dp, 0, sizeof(dp));
    printf("%d\n", min(go(n-1,0), go(n-1,1)));
  }
  return 0;
}
