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
const int N = 2e5+5;

int n, q, a[N], mi[N], ma[N];
int bit[N], ans[N];

void add(int p, int v) {
  for (p+=2; p < N; p+=p&-p) bit[p]+=v;
}

int query(int p) {
  int sum = 0;
  for (p+=2; p; p-=p&-p) sum += bit[p];
  return sum;
}

int main() {
  scanf("%d%d", &n, &q);

  for (int i = 0; i <= q+1; i++) mi[i] = INF, ma[i] = -INF;

  set<pii> s;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s.insert({ -a[i], i });

    mi[a[i]] = min(mi[a[i]], i);
    ma[a[i]] = max(ma[a[i]], i);

    if (!a[i]) add(i, 1);
  }

  for (int i = q+1; i >= 0; i--) if (mi[i] == INF) mi[i] = mi[i+1], ma[i] = ma[i+1];

  int p = -s.begin()->st;
  for (auto x : s) {
    int v = -x.st;
    if (v < p) {
      if (query(ma[p]) - query(mi[p]-1) != ma[p]-mi[p]+1)
        return !printf("NO\n");
      p = v;
    }
    if (v == 0) break;

    add(x.nd, 1);
  }

  memset(bit, 0, sizeof bit);
  for (int i = 1; i <= q; i++) {
    int v = query(mi[i]);
    add(mi[i], i-v);
    add(ma[i]+1, -i+v);
  }

  int mrk = 0;
  for (int i = 1; i <= n; i++) {
    ans[i] = query(i);
    if (ans[i] == q) mrk = 1;
  }

  /*
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  */

  for (int i = 1; i <= n and !mrk; i++) if (!a[i]) ans[i] = q, mrk = 1;
  for (int i = 1; i <= n; i++) if (!ans[i]) ans[i] = max(ans[i-1], ans[i+1]);
  for (int i = n; i >= 1; i--) if (!ans[i]) ans[i] = max(ans[i-1], ans[i+1]);
  for (int i = 1; i <= n; i++) if (!ans[i]) ans[i] = q;

  int okq = 0, ok = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] and ans[i] != a[i]) ok = 0;
    if (ans[i] == q) okq = 1;
  }
  if (!ok or !okq) return !printf("NO\n");

  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
