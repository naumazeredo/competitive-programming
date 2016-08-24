#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, m, q, v[N*N], a[2], b[2], h, w;
int u[N*N], d[N*N], l[N*N], r[N*N];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
    int e = i*(m+2)+j;
    scanf("%d", &v[e]);
  }

  for (int i = 0; i <= n+1; ++i) for (int j = 0; j <= m+1; ++j) {
    int e = i*(m+2)+j;
    r[e] = e+1;
    l[e] = e-1;
    u[e] = e-(m+2);
    d[e] = e+(m+2);
  }

  /*
  for (int i = 0; i <= n; ++i) {
    int x = i*(m+2);
    for (int j = 0; j <= m; ++j) {
      printf("%2d ", r[x]);
      x = r[x];
    }
    printf("\n");
  }
  printf("\n");
  */

  for (int i = 0; i < q; ++i) {
    for (int j = 0; j < 2; ++j) scanf("%d%d", &a[j], &b[j]);
    scanf("%d%d", &h, &w);

    int x[2], y[2];

    for (int j = 0; j < 2; ++j) {
      x[j] = a[j]*(m+2);
      for (int k = 0; k < b[j]; ++k) x[j] = r[x[j]];
    }

    //db(x[0] _ x[1]);

    y[0] = x[0]; y[1] = x[1];
    for (int j = 0; j < w; ++j) {
      swap(d[u[y[0]]], d[u[y[1]]]);
      swap(u[y[0]], u[y[1]]);
      y[0] = r[y[0]];
      y[1] = r[y[1]];
    }

    y[0] = l[y[0]]; y[1] = l[y[1]];
    for (int k = 0; k < h; ++k) {
      swap(l[r[y[0]]], l[r[y[1]]]);
      swap(r[y[0]], r[y[1]]);
      y[0] = d[y[0]];
      y[1] = d[y[1]];
    }

    y[0] = x[0]; y[1] = x[1];
    for (int k = 0; k < h; ++k) {
      swap(r[l[y[0]]], r[l[y[1]]]);
      swap(l[y[0]], l[y[1]]);
      y[0] = d[y[0]];
      y[1] = d[y[1]];
    }

    y[0] = u[y[0]]; y[1] = u[y[1]];
    for (int j = 0; j < w; ++j) {
      swap(u[d[y[0]]], u[d[y[1]]]);
      swap(d[y[0]], d[y[1]]);
      y[0] = r[y[0]];
      y[1] = r[y[1]];
    }

    /*
    for (int i = 0; i <= n; ++i) {
      int x = i*(m+2);
      for (int j = 0; j <= m; ++j) {
        printf("%2d ", r[x]);
        x = r[x];
      }
      printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= n; ++i) {
      int x = i*(m+2);
      for (int j = 1; j <= m; ++j) {
        x = r[x];
        printf("%d ", v[x]);
      }
      printf("\n");
    }
    printf("\n");
    */
  }

  for (int i = 1; i <= n; ++i) {
    int x = i*(m+2);
    for (int j = 1; j <= m; ++j) {
      x = r[x];
      printf("%d ", v[x]);
    }
    printf("\n");
  }

  return 0;
}
