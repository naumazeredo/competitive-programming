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
const int N = 20, M = 1e4+5;

int n, m, a[N][M];
vector<int> order;
int vis[N];

int test(int k) {
  for (int i = 1; i < m; i++) {
    /*
    for (int j = 1; j < n; j++) {
      if (abs(a[order[j]][i] - a[order[j-1]][i]) < k) return 0;
    }
    */
    if (abs(a[order[0]][i] - a[order.back()][i-1]) < k) return 0;
  }

  return 1;
}

int dfs(int k, int u) {
  order.push_back(u);
  if ((int)order.size() == n) {
    if (test(k)) return 1;
    order.pop_back();
    return 0;
  }

  vis[u] = 1;
  for (int i = 0; i < n; i++) if (!vis[i]) {
    int ok = 1;
    for (int j = 0; j < m; j++) if (abs(a[i][j] - a[u][j]) < k) { ok = 0; break; }

    if (ok and dfs(k, i)) return 1;
  }
  vis[u] = 0;

  order.pop_back();
  return 0;
}

int test_bb(int k) {
  for (int i = 0; i < n; i++) {
    memset(vis, 0, sizeof vis);
    order.clear();
    if (dfs(k, i)) return 1;
  }
  return 0;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);

  int lo = 0, hi = 1e9+5;
  while (lo < hi) {
    int mid = (lo+hi+1)/2;
    if (test_bb(mid)) lo = mid;
    else hi = mid-1;
  }
  printf("%d\n", lo);

  return 0;
}
