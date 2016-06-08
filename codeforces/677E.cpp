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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e3+5;

int di[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dj[] = { 0, 0, -1, 1, -1,  1, -1, 1};

int n, m[N][N];
int s[8][N][N], c2[8][N][N], c3[8][N][N];
int vis[8][N][N];

int b2, b3;
ld lg3;

bool better(int v2, int v3) { return v2+lg3*v3 > b2+lg3*b3; }
bool valid(int i, int j) { return (i>0 and j>0 and i<=n and j<=n); }

void dfs(int d, int i, int j) {
  vis[d][i][j]=1;
  int ni=i+di[d], nj=j+dj[d];
  if (valid(ni, nj) and !vis[d][ni][nj]) dfs(d, ni, nj);

  if (!m[i][j]) { s[d][i][j]=c2[d][i][j]=c3[d][i][j]=0; return; }
  s[d][i][j] = s[d][ni][nj]+1;
  c2[d][i][j] = c2[d][ni][nj]+(m[i][j]==2);
  c3[d][i][j] = c3[d][ni][nj]+(m[i][j]==3);
}

void go(int p) {
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
    int t = INF;
    for (int a = 0; a < 4; ++a)
      dfs(p+a, i, j), t = min(t, s[p+a][i][j]);

    int v2 = -3*(m[i][j]==2), v3 = -3*(m[i][j]==3);
    for (int a = 0; a < 4; ++a) {
      v2 += c2[p+a][i][j]-c2[p+a][i+t*di[p+a]][j+t*dj[p+a]];
      v3 += c3[p+a][i][j]-c3[p+a][i+t*di[p+a]][j+t*dj[p+a]];
    }

    if (better(v2, v3)) b2 = v2, b3 = v3;
  }
}

int main() {
  scanf("%d", &n);
  int cz = 0;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) scanf("%1d", &m[i][j]), cz+=!m[i][j];
  if (cz == n*n) return 0*printf("0\n");

  lg3 = log2((ld)3);
  go(0); go(4);

  ll ans = 1;
  for (int i = 0; i < b2; ++i) ans = (ans*2)%MOD;
  for (int i = 0; i < b3; ++i) ans = (ans*3)%MOD;
  printf("%lld\n", ans);
  return 0;
}
