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
const int N = 25;

int n, m, g[N][N], p[N][N], s[N];
int t[N][N];

int test(int a, int b) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      t[i][j] = g[i][j];
  memset(s, 0, sizeof s);

  for (int k = 1; k <= m; k++) {
    int j = k;
    if (k == a) j = b;
    if (k == b) j = a;

    for (int i = 1; i <= n; i++) {
      //db(k _ i _ t[i][k]);
      if (t[i][k] == j) continue;
      if (s[i]) {
        /*
        db("fail");

        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) printf("%d ", t[i][j]);
          printf("\n");
        }
        */

        return 0;
      }
      s[i] = 1;
      swap(t[i][k], t[i][p[i][j]]);
    }
  }

  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &g[i][j]),
      p[i][g[i][j]] = j;

  int ok = test(0, 0);
  for (int i = 1; i <= m; i++)
    for (int j = i+1; j <= m; j++)
      ok |= test(i, j);
  printf("%s\n", ok ? "YES" : "NO");
  /*
  int a = test(2, 3);
  db(a);
  */

  return 0;
}
