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

int n, m, g[N][N], r[4*N][4*N];
char c;


int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    scanf(" %c", &c);
    g[i][j] = c=='X';
  }

  int imi = INF, ima = 0, jmi = INF, jma = 0;
  for (int k = 0; k < n; ++k) for (int l = 0; l < m; ++l) if (g[k][l]) {
    imi = min(imi, k); ima = max(ima, k);
    jmi = min(jmi, l); jma = max(jma, l);
  }

  int ok = 1;
  for (int k = imi; k <= ima; ++k) for (int l = jmi; l <= jma; ++l)
    if (!g[k][l]) { ok = 0; break; }

  if (ok) return 0*printf("YES\n");

  printf("NO\n");
  return 0;
}
