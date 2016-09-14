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
const int N = 1e2+5, P = (1<<16);

int n;
ll dp[N][P], fat[20], anssum, ansmax[P], ansmin[P];

ll cut(ll x, ll v) {
  ll p = 0, res = 0;
  while (x) {
    ll k = x&15;
    if (k != v) res += k<<p, p += 4;
    x >>= 4;
  }
  return res;
}

int main() {
  fat[0] = 1;
  for (int i = 1; i < 20; ++i) fat[i] = (fat[i-1] * i)%MOD;

  scanf("%x", &n);
  for (int i = 0; i < n; ++i) scanf("%llx", &dp[i][0]);

  for (int i = 0; i < n; ++i) for (int j = 1; j < P; ++j) {
    dp[i][j] = cut(dp[i][j-(j&-j)], __builtin_ctz(j&-j));

    ll f = __builtin_popcount(j);
    f = (fat[16-f] * fat[f])%MOD;
    anssum = (anssum + ((dp[i][j]%MOD) * f)%MOD)%MOD;
  }

  cl(ansmin,63);
  ansmin[0] = 0;
  for (int i = 1; i < P; ++i) {
    ll res = 0;
    for (int k = 0; k < n; ++k) res += dp[k][i];

    for (int j = 0; j < 16; ++j) if (i&(1<<j)) {
      ansmax[i] = max(ansmax[i], res + ansmax[i-(1<<j)]);
      ansmin[i] = min(ansmin[i], res + ansmin[i-(1<<j)]);
    }
  }

  printf("%llx %llx %llx\n", ansmin[P-1], ansmax[P-1], anssum);

  return 0;
}
