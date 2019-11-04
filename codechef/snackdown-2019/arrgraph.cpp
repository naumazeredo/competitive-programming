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
const int N = 55;

int t, n, a[N];
int vis[N];

void dfs(int u) {
  vis[u] = 1;
  for (int v = 0; v < n; v++) if (!vis[v] and gcd(a[v], a[u]) == 1)
    dfs(v);
}

int count() {
  int res = 0;
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++) if (!vis[i]) dfs(i), res++;
  return res;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int ans = 0;
    if (count() != 1) {
      ans = 1;

      int ok = 0;
      for (int i = 0; i < n and !ok; i++) {
        int v = a[i];
        for (int j = 2; j <= 50 and !ok; j++) {
          a[i] = j;
          if (count() == 1) ok = 1;
        }

        if (ok) break;
        a[i] = v;
      }
    }

    printf("%d\n", ans);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
  }
  return 0;
}
