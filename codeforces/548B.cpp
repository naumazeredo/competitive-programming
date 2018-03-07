#include <bits/stdc++.h>
using namespace std;

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
const int N = 5e2+5;

int n, m, q, a, b;
int mat[N][N];
int ans[N], acc[N];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    mat[i][0] = -1;
    for (int j = 1; j <= m; j++)
      scanf("%d", &mat[i][j]);
  }

  for (int i = 1; i <= n; i++) {
    ans[i] = 0;
    for (int j = 1; j <= m; j++) {
      acc[j] = mat[i][j];
      if (mat[i][j] == 1 and mat[i][j-1] == 1) acc[j] += acc[j-1];
      ans[i] = max(ans[i], acc[j]);
    }
  }

  for (int i = 0; i < q; i++) {
    scanf("%d%d", &a, &b);

    mat[a][b] = 1-mat[a][b];

    ans[a] = 0;
    for (int j = 1; j <= m; j++) {
      acc[j] = mat[a][j];
      if (mat[a][j] == 1 and mat[a][j-1] == 1) acc[j] += acc[j-1];
      ans[a] = max(ans[a], acc[j]);
    }

    int res = 0;
    for (int j = 1; j <= n; j++)
      res = max(res, ans[j]);
    printf("%d\n", res);
  }

  return 0;
}
