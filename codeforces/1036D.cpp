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
const int N = 3e5+5;

int n, m, a[N], b[N];
vector<ll> va, vb;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), va.push_back(a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]), vb.push_back(b[i]);

  while (va.size()) {
    if (va.back() == vb.back()) {
      db(1);
      va.pop_back();
      vb.pop_back();
    } else if (va.back() < vb.back()) {
      if (va.size() < 2) return !printf("-1\n");
      ll v = va.back(); va.pop_back();
      v += va.back(); va.pop_back();
      va.push_back(v);
      n--;
    } else {
      if (vb.size() < 2) return !printf("-1\n");
      ll v = vb.back(); vb.pop_back();
      v += vb.back(); vb.pop_back();
      vb.push_back(v);
    }
  }
  if (vb.size()) return !printf("-1\n");

  printf("%d\n", n);
  return 0;
}
