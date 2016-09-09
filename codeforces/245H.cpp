// template
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
const int N = 5e3+5;

int n, q, l, r, p[N][N], dp[N][N];
char s[N];

int gop(int i, int j) {
  if (i >= j) return 1;
  if (p[i][j]>=0) return p[i][j];
  return p[i][j] = s[i]==s[j] ? gop(i+1, j-1) : 0;
}

int go(int i, int j) {
  if (i == j) return 1;
  if (i > j) return 0;
  if (dp[i][j]>=0) return dp[i][j];

  return dp[i][j] = gop(i, j) + go(i+1, j) + go(i, j-1) - go(i+1, j-1);
}

int main() {
  cl(dp,-1); cl(p,-1);

  scanf("%s", s);
  n = strlen(s);

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &l, &r);
    printf("%d\n", go(l-1, r-1));
  }
  return 0;
}
