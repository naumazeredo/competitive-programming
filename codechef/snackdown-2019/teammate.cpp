// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5, M = 1e6+5;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return 1ll*a*b % MOD;
}

int fexp(int a, int b) {
  int r = 1;
  for (a %= MOD; b; a = mul(a, a), b >>= 1) if (b&1) r = mul(r, a);
  return r;
}

int inv(int a) {
  return fexp(a, MOD-2);
}

int t, n, s, v[M], f[M];

int main() {
  f[0] = 1;
  for (int i = 1; i < M; i++) f[i] = mul(i, f[i-1]);

  scanf("%d", &t);
  while (t--) {
    memset(v, 0, sizeof v);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &s), v[s]++;

    int ans = 1;
    for (int i = 1; i < M and n; i++) while (v[i]) {
      //db(i _ v[i] _ ans);

      if ((n%2) == 0 and v[i] >= 2) {
        int cnt = 0;
        while (n and v[i] >= 2) {
          ll x = 1ll * v[i] * (v[i]-1) / 2;
          x %= MOD;

          ans = mul(ans, x);

          v[i] -= 2;
          n -= 2;
          cnt++;
        }

        ans = mul(ans, inv(f[cnt]));
      } else {
        ans = mul(ans, v[i]);
        v[i]--;
        n--;
      }
    }

    assert(ans >= 0 and ans < MOD);
    printf("%d\n", ans);
  }
  return 0;
}
