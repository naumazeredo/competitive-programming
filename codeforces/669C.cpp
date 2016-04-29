#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, m, q;
int t[11111];
int a[11111];
int b[11111];
int c[11111];
int d[222][222];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d", &t[i]);
    if (t[i] == 1) scanf("%d", &a[i]);
    if (t[i] == 2) scanf("%d", &a[i]);
    if (t[i] == 3) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  }

  for (int i = q-1; i >= 0; --i) {
    if (t[i] == 1) {
      int tmp = d[a[i]][m];
      for (int j = m; j > 1; --j) d[a[i]][j] = d[a[i]][j-1];
      d[a[i]][1] = tmp;
    }
    if (t[i] == 2) {
      int tmp = d[n][a[i]];
      for (int j = n; j > 1; --j) d[j][a[i]] = d[j-1][a[i]];
      d[1][a[i]] = tmp;
    }
    if (t[i] == 3) {
      d[a[i]][b[i]] = c[i];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      printf("%d ", d[i][j]);
    printf("\n");
  }

  return 0;
}
