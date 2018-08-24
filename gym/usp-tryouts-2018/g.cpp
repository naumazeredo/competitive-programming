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
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5, SQ = 450;

int n, q;
pii g[N], b[SQ];

pii join(pii a, pii b) { return { max(a.st, b.st), min(a.nd, b.nd) }; }
int val(pii a) { return max(0, a.nd-a.st+1); }

void update(int p) {
  b[p] = { -INF, INF };
  for (int i = p*SQ; i < (p+1)*SQ; i++) {
    b[p] = join(b[p], g[i]);
  }
}

void update(int p, int l, int r) {
  g[p] = { l, r };
  update(p/SQ);
}

int query(int l, int r) {
  pii res = { -INF, INF };

  if (l/SQ == r/SQ) {
    for (int i = l; i <= r; i++) res = join(res, g[i]);
  } else {
    for (int i = l/SQ+1; i < r/SQ; i++) res = join(res, b[i]);
    for (int i = l; i < (l/SQ+1)*SQ; i++) res = join(res, g[i]);
    for (int i = r/SQ*SQ; i <= r; i++) res = join(res, g[i]);
  }

  return val(res);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d%d", &g[i].st, &g[i].nd);
  for (int i = 0; i < n/SQ; i++) update(i);

  for (int i = 0; i < q; i++) {
    char t;
    scanf(" %c", &t);
    if (t == 'C') {
      int p, l, r;
      scanf("%d%d%d", &p, &l, &r);
      update(p, l, r);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", query(l, r));
    }
  }

  return 0;
}
