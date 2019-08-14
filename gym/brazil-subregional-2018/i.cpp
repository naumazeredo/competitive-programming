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
const int N = 1e3+3;

int n, m, l;
bitset<1005> b[N], x;

int main() {
  scanf("%d%d%d", &n, &m, &l);
  for (int y, i = 0; i < l; i++) scanf("%d", &y), x.set(y);
  for (int k, i = 0; i < n; i++) {
    scanf("%d", &k);
    for (int y, j = 0; j < k; j++) scanf("%d", &y), b[i].set(y);
  }

  int ans = 0, i = 0;
  while (x.count() and ans < 2*n) {
    x ^= b[i];
    i = (i+1)%n;
    ans++;
  }

  printf("%d\n", ans < 2*n ? ans : -1);

  return 0;
}
