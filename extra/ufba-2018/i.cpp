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

int n, q, h[N];
int st[4*N];

void build(int p = 1, int l = 0, int r = n) {
  if (l == r) { st[p] = abs(h[l+1]-h[l]); return; }
  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  st[p] = max(st[2*p], st[2*p+1]);
}

void update(int x, int v, int p = 1, int l = 0, int r = n) {
  if (l > x or r < x) return;
  if (l == r) { st[p] = v; return; }
  int m = (l+r)/2;
  update(x, v, 2*p, l, m);
  update(x, v, 2*p+1, m+1, r);
  st[p] = max(st[2*p], st[2*p+1]);
}

int query(int i, int j, int p = 1, int l = 0, int r = n) {
  if (l > j or r < i) return -INF;
  if (i <= l and r <= j) return st[p];
  int m = (l+r)/2;
  return max(query(i, j, 2*p, l, m), query(i, j, 2*p+1, m+1, r));
}

int solve(int p, int v) {
  int lo, hi, ans = 1;

  // right
  if (query(p, p) <= v) {
    lo = p, hi = n;
    while (lo < hi) {
      int md = (lo+hi)/2;
      //db(lo _ md _ hi _ query(p, md));
      if (query(p, md) <= v) lo = md+1;
      else hi = md;
    }
    //db(lo _ lo-p);
    ans += lo-p;
  }

  if (query(p-1, p-1) <= v) {
    lo = 0, hi = p-1;
    while (lo < hi) {
      int md = (lo+hi+1)/2;
      if (query(md, p-1) <= v) hi = md-1;
      else lo = md;
    }
    //db(lo _ p-1-lo);
    ans += p-1-lo;
  }

  return ans;
}

int main() {
  scanf("%d%d", &n, &q);
  h[0] = h[n+1] = INF;
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  build();
  for (int t, p, v, i = 0; i < q; i++) {
    scanf("%d%d%d", &t, &p, &v);
    if (t == 1) {
      h[p] = v;
      update(p, abs(h[p+1]-h[p]));
      update(p-1, abs(h[p]-h[p-1]));
    } else {
      printf("%d\n", solve(p, v));
    }
  }
  return 0;
}
