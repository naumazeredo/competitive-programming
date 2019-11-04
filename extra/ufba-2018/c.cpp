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
const int N = 1e5+5;

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

int fexp(ll a, ll b) {
  int r = 1;
  for (a%=MOD; b; b>>=1, a=mul(a,a)) if (b&1) r=mul(r,a);
  return r;
}

int p2(ll b) { return fexp(2, b); }

int t;
ll n;

int solve() {
  int x, y;
  int p = p2(n);

  x = sub(mul(n%MOD, p), sub(p, 1));
  y = sub(sub(add(p,p),1), add(n%MOD,1));
  return sub(x, y);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    printf("%d\n", solve());
  }
  return 0;
}
