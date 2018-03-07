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
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5, M = 25;

int n, x, y;
int s[M][N], pw[N];
int p[N];

int main() {
  for (ll i = 2; i < N; i++) if (!p[i]) {
    for (ll j = i*i; j < N; j+=i) p[j] = i;
    p[i] = i;
  }

  for (int i = 0; i < N; i++) s[0][i] = 1;
  for (int i = 1; i < M; i++) s[i][0] = 1;
  for (int i = 1; i < M; i++) s[i][1] = s[i-1][1]+1;
  for (int j = 2; j < N; j++)
    for (int i = 1; i < M; i++)
      s[i][j] = (s[i-1][j] + s[i][j-1])%MOD;

  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = (pw[i-1]*2)%MOD;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    map<int, int> m;
    while (x != 1) m[p[x]]++, x /= p[x];

    ll ans = pw[y-1];
    for (auto x : m) ans = (ans * s[x.nd][y-1])%MOD;
    printf("%lld\n", ans);
  }
  return 0;
}
