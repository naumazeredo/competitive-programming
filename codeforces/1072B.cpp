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

int n, a[N], b[N], t[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) scanf("%d", &b[i]);

  for (int k = 0; k < 2; k++)
    for (int i = 1; i < n; i++) if (b[i]&(1<<k))
      t[i] |= (1<<k), t[i+1] = (1<<k);

  for (int k = 0; k < 2; k++)
    for (int i = 1; i < n; i++) if (a[i]&(1<<k) and !((t[i]|t[i+1])&(1<<k))) {
      if (t[i-1]&(1<<k)) t[i+1] |= (1<<k);
      else t[i] |= (1<<k);
    }

  for (int i = 1; i < n; i++)
    if (a[i] != (t[i]|t[i+1]) or b[i] != (t[i]&t[i+1]))
    return printf("NO\n"), 0;

  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%d ", t[i]);
  printf("\n");

  return 0;
}
