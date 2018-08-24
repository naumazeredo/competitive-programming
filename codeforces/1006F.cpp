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
const int N = 21;

const int di[] = {1, 0, -1,  0};
const int dj[] = {0, 1,  0, -1};

int n, m;
ll k, g[N][N], ans;
vector<ll> mm[N][N];

void dfs_br(int i, int j, int d, ll x) {
  x ^= g[i][j];
  if (d == (n+m)/2) {
    mm[i][j].push_back(x);
    return;
  }

  for (int p = 0; p < 2; p++) {
    int ni = i + di[p];
    int nj = j + dj[p];
    if (ni < 0 or ni > n or nj < 0 or nj > m) continue;
    dfs_br(ni, nj, d+1, x);
  }
}

void dfs_tl(int i, int j, int d, ll x) {
  if (d == (n+m+1)/2) {
    int t = upper_bound(mm[i][j].begin(), mm[i][j].end(), x^k) -
            lower_bound(mm[i][j].begin(), mm[i][j].end(), x^k);
    ans += t;
    return;
  }
  x ^= g[i][j];

  for (int p = 2; p < 4; p++) {
    int ni = i + di[p];
    int nj = j + dj[p];
    if (ni < 0 or ni > n or nj < 0 or nj > m) continue;
    dfs_tl(ni, nj, d+1, x);
  }
}

int main() {
  scanf("%d%d%lld", &n, &m, &k);
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%lld", &g[i][j]);

  dfs_br(1, 1, 1, 0);
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    sort(mm[i][j].begin(), mm[i][j].end());
  dfs_tl(n, m, 1, 0);

  printf("%lld\n", ans);

  return 0;
}
