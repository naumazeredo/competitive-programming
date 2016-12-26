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
const int N = 1e4+5;

int n, a, b, c, dp[N];

int go(int v) {
  if (v < 0) return -INF;
  if (v == 0) return 0;
  if (dp[v]) return dp[v];
  dp[v] = 1 + max(go(v-a), max(go(v-b), go(v-c)));
  return dp[v];
}

int main() {
  scanf("%d%d%d%d", &n, &a, &b, &c);
  printf("%d\n", go(n));
  return 0;
}
