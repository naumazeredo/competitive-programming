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
const int N = 1e5+5;

ll l, r, p10;
ll dp[20][20], pw[20], q[20][20];

ll solv(ll x) {
  if (x == 0) return 0;
  vi d, tmp;
  ll xx = x;
  while (xx) tmp.pb(xx%10), xx/=10;
  while (tmp.size()) d.pb(tmp.back()), tmp.pop_back();

  ll extra = 0;
  int i = d[0], j = d.size();
  if (j == 1) return dp[i+1][j];
  if (j == 2) return dp[i][j] + (d[0]<=d[1]);

  if (d[0] <= d[j-1]) extra = (x%pw[j])/10+1;
  else for(int k = j-2; k > 0; k--) extra += d[j-k-1]?q[d[j-k-1]][k]:0;

  return dp[i][j] + extra;
}

int main() {
  for (int i = 1; i <= 10; i++) dp[i][1] = i-1, q[i][1] = i;
  pw[1] = p10 = 1;
  for (int i = 2; i <= 19; i++) {
    p10 *= 10;
    pw[i] = p10;

    dp[0][i] = dp[9][i-1]; q[0][i] = q[9][i-1];
    dp[1][i] = dp[10][i-1]; q[1][i] = q[10][i-1];
    for (int j = 2; j <= 10; j++) dp[j][i] = dp[j-1][i]+pw[i-1], q[j][i] = q[j-1][i] + pw[i];
  }

  //for (int i = 1; i <= 3; i++) for (int j = 1; j < 10; j++) db(j _ i _ dp[j][i]);
  //for (int i = 1; i <= 3; i++) for (int j = 1; j < 10; j++) db(j _ i _ q[j][i]);

  scanf("%lld%lld", &l, &r);

  /*
  db(l _ solv(l));
  db(l-1 _ solv(l-1));
  db(r _ solv(r));
  */

  printf("%lld\n", solv(r)-solv(l-1));

  return 0;
}
