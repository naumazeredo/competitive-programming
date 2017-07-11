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

int n, v;
ll dp[10];

int main() {
  scanf("%d", &n);
  cl(dp,-1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v);
    ll tmp[10] = {};
    tmp[v%7] = v;
    for (int j = 0; j < 7; ++j) if (dp[j]>0)
      tmp[(j+v%7)%7] = dp[j] + v;
    for (int j = 0; j < 7; ++j)
      dp[j] = max(dp[j], tmp[j]);
  }
  printf("%lld\n", dp[0]);
  return 0;
}
