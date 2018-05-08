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
const int N = 1e5+5;

int n, k, p[N], dp[N];

int main() {
  memset(dp, -1, sizeof dp);

  scanf("%d%d", &n, &k);
  for (int x, i = 0; i < n; i++) {
    scanf("%d", &x);
    if (dp[x] != -1) printf("%d ", dp[x]);
    else {
      int v = x, j;
      for (j = 0; j < k and x-j >= 0; j++) {
        if (dp[x-j] != -1) {
          if (x - dp[x-j] < k) v = dp[x-j];
          break;
        } else v = x-j;
      }

      j--;
      for (; j >= 0; j--) dp[x-j] = v;

      printf("%d ", dp[x]);
    }
  }

  printf("\n");

  return 0;
}
