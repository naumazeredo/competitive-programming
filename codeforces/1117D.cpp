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
const int N = 101;

ll n, m;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return 1ll*a*b%MOD;
}

struct mat {
  int v[N][N];

  mat() {
    memset(v, 0, sizeof v);
  }

  void ident() {
    for (int i = 0; i < m; i++) v[i][i] = 1;
  }

  void print() const {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++)
        db(i _ j _ v[i][j]);
  }
};

mat mul(const mat& a, const mat& b) {
  mat r;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      int v = 0;
      for (int k = 0; k < m; k++) {
        v = add(v, mul(a.v[i][k], b.v[k][j]));
      }

      r.v[i][j] = v;
    }
  }
  return r;
}

mat fexp(mat a, ll b) {
  mat r;
  r.ident();

  mat x = a;

  for (; b; b>>=1, x = mul(x,x)) if (b&1) r = mul(r,x);
  return r;
}

int main() {
  scanf("%lld%lld", &n, &m);
  if (n < m) return printf("1\n"), 0;

  mat a;
  a.v[0][0] = 1; a.v[0][m-1] = 1;
  for (int i = 1; i < m; i++) a.v[i][i-1] = 1;

  mat b = fexp(a, n-m+1);

  int ans = 0;
  for (int i = 0; i < m; i++) ans = add(ans, b.v[0][i]);

  printf("%d\n", ans);

  return 0;
}
