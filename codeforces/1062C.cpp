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

int n, q, x[N], p[N], p2[N], s2[N];

int main() {
  p2[0] = s2[0] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = mul(2, p2[i-1]);
    s2[i] = add(s2[i-1], p2[i]);
  }

  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%1d", &x[i]), p[i] = p[i-1] + x[i];
  for (int l, r, i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    int s = r-l+1;
    int t = p[r] - p[l-1];
    printf("%d\n", add(t ? s2[t-1] : 0, mul(sub(p2[t], 1), s-t ? s2[s-t-1] : 0)));
  }
  return 0;
}
