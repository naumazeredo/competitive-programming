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
const int N = 3e4+5, SQ = 200;

struct query { int i, l, r; };
bool operator<(query a, query b) {
  if (a.l/SQ == b.l/SQ) //return ((a.l/SQ)&1) ? a.r > b.r : a.r < b.r;
    return a.r < b.r;
  return a.l < b.l;
}

int n, q, v[N], f[N], ans[N];
query qs[N];

int bit[N];

void bitadd(int p, int v) {
  for (p+=2; p < N; p+=p&-p) bit[p]+=v;
}

int bitsum(int p) {
  int sum = 0;
  for (p+=2; p; p-=p&-p) sum+=bit[p];
  return sum;
}

void add(int p) {
  int x = v[p];
  bitadd(f[x], -1);
  f[x]++;
  bitadd(f[x], +1);
}

void rem(int p) {
  int x = v[p];
  bitadd(f[x], -1);
  f[x]--;
  bitadd(f[x], +1);
}

int get_ans() {
  int lo = 0, hi = N;
  while (lo < hi) {
    int md = (lo+hi+1)/2;
    int x = bitsum(N)-bitsum(md-1);
    if (x >= md) lo = md;
    else hi = md-1;
  }

  return lo;
}

int main() {
  scanf("%d%d", &n, &q);

  vector<int> s;
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]), s.push_back(v[i]);
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  for (int i = 1; i <= n; i++)
    v[i] = lower_bound(s.begin(), s.end(), v[i]) - s.begin();

  for (int i = 0; i < q; i++) scanf("%d%d", &qs[i].l, &qs[i].r), qs[i].i = i;
  sort(qs, qs+q);

  bitadd(0, s.size());

  int l = 1, r = 0;
  for (int i = 0; i < q; i++) {
    while (r < qs[i].r) add(++r);
    while (r > qs[i].r) rem(r--);
    while (l > qs[i].l) add(--l);
    while (l < qs[i].l) rem(l++);

    ans[qs[i].i] = get_ans();
  }

  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);

  return 0;
}
