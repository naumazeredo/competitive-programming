// @subject: Mo algorithm optimization, sqrt decomposition
// @diff: 4

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

const int N = 5e5+5, S = 800;

int n, a[N], q, bl[S], cnt[N], ans[N];
piii qs[N];

void add(int x) {
  cnt[x]++;
  if (cnt[x] == 1) bl[x/S]++;
  if (cnt[x] == 2) bl[x/S]--;
}

void rem(int x) {
  cnt[x]--;
  if (cnt[x] == 1) bl[x/S]++;
  if (cnt[x] == 0) bl[x/S]--;
}

int get() {
  for (int i = 0; i < S; i++) if (bl[i])
    for (int j = i*S;; j++) if (cnt[j] == 1)
      return j;
  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) scanf("%d%d", &qs[i].nd.st, &qs[i].nd.nd), qs[i].st = i;

  sort(qs, qs+q, [](piii a, piii b) {
         if (a.nd.st/S == b.nd.st/S)
           return ((a.nd.st/S)&1) ? a.nd.nd > b.nd.nd : a.nd.nd < b.nd.nd;
         return a.nd.st < b.nd.st;
       });

  int cl = 1, cr = 0;
  for (int i = 0; i < q; i++) {
    int ind = qs[i].st;
    int l = qs[i].nd.st;
    int r = qs[i].nd.nd;

    while (cr < r) add(a[++cr]);
    while (cr > r) rem(a[cr--]);
    while (cl < l) rem(a[cl++]);
    while (cl > l) add(a[--cl]);

    ans[ind] = get();
  }

  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);

  return 0;
}
