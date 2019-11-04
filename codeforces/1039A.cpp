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
const int N = 2e5+5;

int n, x[N];
ll t;
ll a[N], b[N];

int main() {
  scanf("%d%lld", &n, &t);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);

  //for (int i = 2; i <= n; i++) if (x[i] < x[i-1]) return !printf("No\n");
  for (int i = 1; i <= n; i++) if (x[i] < i) return !printf("No\n");

  fill(b, b+n+1, 1);

  for (int i = 1; i <= n; i++) {
    b[i] = max(b[i], a[i]+t);
    b[x[i]] = max(b[x[i]], a[i]+t);

    int p = x[i]-1;
    if (x[i] > i) p++;
    if (p < 1 or p > n) continue;

    b[x[i]-1] = max(b[x[i]-1], a[p]+t);
  }

  for (int i = 2; i <= n; i++) if (b[i] <= b[i-1]+1) b[i] = b[i-1]+1;

  for (int i = 1; i <= n; i++) db(i _ b[i]);

  for (int i = 1; i <= n; i++) {
    ll nx = x[i]+1;
    if (nx > n) continue;

    int p = nx-1;
    if (nx > i) p++;
    if (p < 1 or p > n) continue;

    //db(i _ x[i] _ nx _ p);

    if (b[nx-1] >= a[p]+t) return !printf("No\n");
  }

  printf("Yes\n");
  for (int i = 1; i <= n; i++) printf("%lld ", b[i]);
  printf("\n");

  return 0;
}
