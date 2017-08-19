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
const int N = 30;

const int di[] = {1, 1, -1, -1};
const int dj[] = {1, -1, -1, 1};

int n, e[4][N][N], p[2], b, bp[4], m[4][N][N];
int sbi[4], sbj[4];
char g[N][N];

int x(int i, int j) { return ((i-j)%4+4)%4; }
int o(int i, int j) { return ((i-j+2)%4+4)%4; }

void dfs(int k, int i, int j) {
  m[k][i][j] = 0;
  for (int l = 0; l < 4; l++) {
    int ni = i+di[l], nj = j+dj[l];
    if (g[ni][nj]=='W' and m[k][ni+di[l]][nj+dj[l]])
      dfs(k, ni+di[l], nj+dj[l]);
  }
}

int main() {
  while (~scanf("%d", &n)) {
    cl(p, 0); cl(bp, 0);
    cl(e, 0); cl(m, 0);
    b = 0;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
      scanf(" %c", &g[i][j]);
      p[i%2] += g[i][j]=='W';
      b += g[i][j]=='W' and (i == 1 or i == n or j == 1 or j == n);
      //if (g[i][j] == 'B') sbi[x(i,j)] = i, sbj[x(i,j)] = j, bp[x(i,j)]++;
    }

    if (b or (p[0] and p[1])) {
      printf("None\n");
      continue;
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (g[i][j] == 'W') {
      e[x(i,j)][i-1][j-1]++; m[x(i,j)][i-1][j-1]=1;
      e[x(i,j)][i+1][j+1]++; m[x(i,j)][i+1][j+1]=1;

      e[o(i,j)][i+1][j-1]++; m[o(i,j)][i+1][j-1]=1;
      e[o(i,j)][i-1][j+1]++; m[o(i,j)][i-1][j+1]=1;
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
      if (g[i][j] == 'B' and m[x(i,j)][i][j])
        sbi[x(i,j)] = i, sbj[x(i,j)] = j, bp[x(i,j)]++;

    /*
    for (int k = 0; k < 4; k++) {
      db(bp[k]);
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d ", e[k][i][j]);
        puts("");
      }
      puts("");
    }
    */

    vector<int> ansi, ansj;
    for (int k = 0; k < 4; k++) if (bp[k] == 1) {
      int odd = 0;
      for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) odd += e[k][i][j]%2;
      if (odd == 0 or (odd == 2 and e[k][sbi[k]][sbj[k]]%2)) {

        int ok = 1;
        dfs(k, sbi[k], sbj[k]);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (m[k][i][j]) ok = 0;
        if (ok) ansi.pb(sbi[k]), ansj.pb(sbj[k]);
      }
    }

    if (ansi.size() == 0) printf("None\n");
    if (ansi.size() == 1) printf("%c%d\n", 'a'+ansj[0]-1, n-ansi[0]+1);
    if (ansi.size() >  1) printf("Multiple\n");
  }
  return 0;
}
