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
const int N = 1e6+5;

int n, m, a, b;
int f[N], p2[N];

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

int mul(int a, int b) {
  return 1ll*a*b%MOD;
}

int fexp(int a, int b) {
  int r = 1;
  for (; b; b>>=1, a=mul(a,a)) if (b&1) r=mul(r,a);
  return r;
}

int inv(int a) { return fexp(a, MOD-2); }

int comb(int n, int k) {
  return mul(f[n], mul(inv(f[n-k]), inv(f[k])));
}

int calc(int k) {
  int res = 0;

  for (int i = 0; i <= k; i++) {
    int v = (i&1) ? MOD-1 : 1;
    v = mul(v, inv(p2[i]));
    v = mul(v, add(k, i));
    v = mul(v, f[i]);
    v = mul(v, comb(k, i));
    v = mul(v, comb(n-k, i));
    v = mul(v, fexp(n, n-k-i-1));

    res = add(res, v);
  }

  return mul(res, comb(n, k));
}

int main() {
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = mul(i, f[i-1]);

  p2[0] = 1;
  for (int i = 1; i < N; i++) p2[i] = mul(2, p2[i-1]);

  scanf("%d%d%d%d", &n, &m, &a, &b);

  for (int i = 2; i <= n; i++) {
  }

  return 0;
}
