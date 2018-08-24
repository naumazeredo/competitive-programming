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
const int N = 1e2+5;

int n, m, a[N], b[N];
int g[N][N];

int main() {
  scanf("%d%d", &n, &m);
  int x = 0;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), x ^= a[i];
  for (int i = 0; i < m; i++) scanf("%d", &b[i]), x ^= b[i];

  if (x) return !printf("NO\n");

  for (int k = 30; k >= 0; k--) {
    int x = 1<<k;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i]&b[j]&x) {
          a[i] -= x;
          b[j] -= x;
          g[i][j] += x;
        }
      }
    }
  }

  for (int k = 30; k >= 0; k--) {
    int x = 1<<k;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (a[i]&a[j]&x) {
          for (int l = 0; l < m; l++) {
            if (!(g[i][l]&x) and !(g[j][l]&x)) {
              g[i][l] += x;
              g[j][l] += x;
              a[i] -= x;
              a[j] -= x;
              break;
            }
          }
        }
      }
    }
  }

  for (int k = 30; k >= 0; k--) {
    int x = 1<<k;
    for (int i = 0; i < m; i++) {
      for (int j = i+1; j < m; j++) {
        if (b[i]&b[j]&x) {
          for (int l = 0; l < n; l++) {
            if (!(g[l][i]&x) and !(g[l][j]&x)) {
              g[l][i] += x;
              g[l][j] += x;
              b[i] -= x;
              b[j] -= x;
              break;
            }
          }
        }
      }
    }
  }

  int ok = 1;
  for (int i = 0; i < n; i++) if (a[i]) ok = 0;
  for (int i = 0; i < m; i++) if (b[i]) ok = 0;

  if (ok) {
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) printf("%d ", g[i][j]);
      printf("\n");
    }
  } else printf("NO\n");

  return 0;
}
