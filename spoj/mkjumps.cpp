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
const int N = 1e5+5;

int n, a, b, t, q, ans;
int g[20][20];
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void dfs(int x, int y, int p) {
  q = max(q, p);
  g[y][x] = 2;
  for (int i = 0; i < 8; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if (nx >= 0 and nx <= 10 and ny >= 0 and ny <= 10 and g[ny][nx]==1) {
      dfs(nx,ny,p+1);
    }
  }
  g[y][x] = 1;
}

int main() {
  int tt = 0;
  while (~scanf("%d", &n) and n) {
    tt++;
    cl(g,0);
    t = 0; q = 0; ans = 0;

    int sx;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a, &b);
      t+=b;
      for (int j = a; j < a+b; ++j) g[i][j] = 1;
      if (!i) sx = a;
    }

    dfs(sx,0,1);
    ans = t - q;
    printf("Case %d, %d square%s can not be reached.\n", tt, ans, ans==1?"":"s");
    fflush(stdout);
  }
  return 0;
}
