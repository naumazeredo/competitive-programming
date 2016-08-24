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
const int N = 1e5+5;

int n, m, ans;
int dig[2];
int dp[2][10];

void go(int h, int d) {
  ll v = 0;
  for (int i = 0; i < d; ++i) v=v*7+dp[h][i];
  if (v >= (h?m:n)) return;

  if (h == 0 and d == dig[0]) go(1, 0);
  if (h == 1 and d == dig[1]) {
    ans++;
    return;
  }

  for (int i = 0; i < 7; ++i) {
    int ok = 1;
    for (int j = 0; j < d; ++j) if (dp[h][j] == i) ok = 0;
    if (h == 1) for (int j = 0; j < dig[0]; ++j) if (dp[0][j] == i) ok = 0;
    if (!ok) continue;
    dp[h][d] = i;
    go(h, d+1);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  int t = n-1;
  while (t) { dig[0]++, t/=7; }
  t = m-1;
  while (t) { dig[1]++, t/=7; }
  dig[0] = max(1, dig[0]);
  dig[1] = max(1, dig[1]);
  go(0, 0);
  printf("%d\n", ans);
  return 0;
}
