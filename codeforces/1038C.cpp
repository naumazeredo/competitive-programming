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
const int N = 1e5+5;

int n, a[2][N], b[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[0][i]); sort(a[0]+1, a[0]+n+1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[1][i]); sort(a[1]+1, a[1]+n+1);

  ll ans = 0;
  int p[2] = {n, n};
  int t = 0;

  while (p[0] or p[1]) {
    //db(t _ p[t] _ p[1-t] _ a[t][p[t]] _ a[1-t][p[1-t]]);
    if (p[t] and a[t][p[t]] >= a[1-t][p[1-t]]) ans += (t ? -1 : 1) * a[t][p[t]], p[t]--;
    else p[1-t]--;
    t = 1-t;
    //db(p[t] _ p[1-t] _ ans);
  }

  printf("%lld\n", ans);

  return 0;
}
