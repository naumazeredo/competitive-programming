// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


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
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5, SQ = 550;

ordered_set b[SQ];
int n, m, u;
ll a[N];

int query(int l, int r, int v) {
  int ans = 0;
  for (int i = l/SQ+1; i < r/SQ; i++)
    ans += b[i].order_of_key({ v, 0 });

  if (l/SQ != r/SQ) {
    for (int i = l; i < (l/SQ+1)*SQ; i++) ans += a[i] < v;
    for (int i = r/SQ*SQ; i <= r; i++) ans += a[i] < v;
  } else {
    for (int i = l; i <= r; i++) ans += a[i] < v;
  }

  return ans;
}

void update(int p, int k, int l, int r) {
  ll val = 1ll*u*k/(r-l+1);
  b[p/SQ].erase({ a[p], p });
  a[p] = val;
  b[p/SQ].insert({ a[p], p });
}

int main() {
  scanf("%d%d%d", &n, &m, &u);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    b[i/SQ].insert({ a[i], i });
  }

  for (int i = 0; i < m; i++) {
    int l, r, v, p;
    scanf("%d%d%d%d", &l, &r, &v, &p);

    int ans = query(l, r, v);
    update(p, ans, l, r);
  }

  for (int i = 1; i <= n; i++) printf("%lld\n", a[i]);

  return 0;
}
