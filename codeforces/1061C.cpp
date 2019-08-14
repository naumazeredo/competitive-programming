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

int n, a[N];
vector<int> d[M];
ll val[M];

ll add(ll a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

ll sub(ll a, ll b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

ll mul(ll a, ll b) {
  return a*b%MOD;
}

int main() {
  for (ll i = 1; i < M; i++)
    for (ll j = i; j < M; j+=i)
      d[j].push_back(i);

  scanf("%d", &n);

  ll ans = 0;
  val[0] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);

    for (int j = (int)d[a[i]].size()-1; j >= 0; j--) {
      int x = d[a[i]][j];
      val[x] = add(val[x], val[x-1]);
      ans = add(ans, val[x-1]);
    }
  }

  printf("%lld\n", ans);
  return 0;
}
