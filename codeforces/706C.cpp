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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int N = 1e5+5;

int n, c[N];
char t[N];
string s[N][2];
ll dp[N][2];

ll go(int i, int j) {
  if (i == 0) return j?c[0]:0;
  if (~dp[i][j]) return dp[i][j];

  ll r = LINF;
  if (s[i][j] >= s[i-1][0]) r = min(r, go(i-1,0) + (j?c[i]:0));
  if (s[i][j] >= s[i-1][1]) r = min(r, go(i-1,1) + (j?c[i]:0));

  return dp[i][j] = r;
}

int main() {
  cl(dp,-1);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  for (int i = 0; i < n; ++i) {
    scanf("%s", t);
    s[i][0] = t;
    for (int j = strlen(t)-1; j>=0; --j) s[i][1] += t[j];
  }

  ll res = min(go(n-1,0),go(n-1,1));
  printf("%lld\n", res==LINF?-1:res);

  return 0;
}
