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
const int N = 35;

int n, m;
char g[N][N];
int k[N][N];
int l[N], c[N]; // red count
int acc;
int ans;

void bt(int i, int j) {
  if (i > n) { ans++; return; }
  if (j > m) {
    int acc_bak = acc;
    acc = 0;
    bt(i+1, 1);
    acc = acc_bak;
    return;
  }

  if (g[i][j] != '.') {
    if (g[i][j] == 'R') l[i]++,c[j]++;
    bt(i, j+1);
    if (g[i][j] == 'R') l[i]--,c[j]--;
    return;
  }

  acc += c[j];
  if (!(l[i] or acc)) {
    // BLUE
    bt(i, j+1);
  }

  // RED
  l[i]++; c[j]++;
  acc++;
  bt(i, j+1);
  acc--;
  l[i]--; c[j]--;

  acc -= c[j];
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf(" %c", &g[i][j]);
  for (int i = n; i >= 1; i--) {
    int b = 0;
    for (int j = m; j >= 1; j--) {
      if (g[i][j+1] == 'B' or g[i][j] == 'B') b = 1;
      if (b and g[i][j] == 'R') return !printf("0\n");
      if (b) g[i][j] = 'B';
    }
  }

  for (int j = m; j >= 1; j--) {
    int b = 0;
    for (int i = n; i >= 1; i--) {
      if (g[i+1][j] == 'B' or g[i][j] == 'B') b = 1;
      if (b and g[i][j] == 'R') return !printf("0\n");
      if (b) g[i][j] = 'B';
    }
  }

  bt(1, 1);
  printf("%d\n", ans);

  return 0;
}
