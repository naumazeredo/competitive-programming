// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

int n, k, a[N];
set<int> s;
ll ans;

ll add(ll a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

ll mul(ll a, ll b) {
  return a*b%MOD;
}

int main() {
  scanf("%d%d", &n, &k);
  vector<pii> v;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), v.push_back({ a[i], i });;
  sort(v.rbegin(), v.rend());

  s.insert(0);
  s.insert(n+1);

  for (auto x : v) {
    auto it = s.insert(x.nd).st;

    it--;
    int l = x.nd - (*it) -1;

    it++;
    it++;
    int r = (*it) - x.nd -1;

    //db(x.st _ x.nd _ l _ r);
    db(x.st _ x.nd);

    for (; l + r + 1 >= k; l = max(0, l-k+1), r = max(0, r-k+1)) {
      int t = min(r,k-1) + min(l, k-1) - k+2;
      db(l _ r _ t);

      ans = add(ans, mul(x.st, t));
    }
  }

  printf("%lld\n", ans);

  return 0;
}
