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
const int N = 5e2+5;

const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

int n, m, g[N][N], d[N][N];

int main() {
  while (~scanf("%d%d", &n, &m)) {
    cl(d,63);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &g[i][j]);

    queue<int> qi, qj;
    qi.push(0); qj.push(0);
    d[0][0] = 0;

    while (qi.size()) {
      int ui = qi.front(); qi.pop();
      int uj = qj.front(); qj.pop();

      for (int i = 0; i < 4; i++) {
        int ni = ui+di[i]*g[ui][uj];
        int nj = uj+dj[i]*g[ui][uj];
        if (ni >= 0 and ni < n and nj >= 0 and nj < m and d[ni][nj] > d[ui][uj]+1)
          d[ni][nj] = d[ui][uj]+1, qi.push(ni), qj.push(nj);
      }
    }

    printf("%d\n", d[n-1][m-1]==INF?-1:d[n-1][m-1]);
  }
  return 0;
}
