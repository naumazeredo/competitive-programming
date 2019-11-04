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

int k;
ll n, m;

set<ll> rows, cols, diag1, diag2;

int main() {
  scanf("%lld%lld%d", &n, &m, &k);
  for (int t, a, b, i = 0; i < k; i++) {
    scanf("%d%d%d", &t, &a, &b);
    if (t&1) {
      rows.insert(a);
      cols.insert(b);
    }
    if (t&1) {
      diag1.insert(a-b);
      diag2.insert(a-m+b);
    }
  }

  ll ans = n*m;
  ans += rows.size() + cols.size() - rows.size() * cols.size();

  return 0;
}
