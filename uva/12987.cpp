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

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int t, v[9][9];
char g[9][9];
set<int> s;

void dfs(int y, int x) {
  v[y][x]=1;
  for (int i = 0; i < 4; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if (nx<0 or nx>=9 or ny<0 or ny>=9) continue;
    if (g[ny][nx] == 'o' and !v[ny][nx]) dfs(ny, nx);
    if (g[ny][nx] == '.') s.insert(ny*9+nx);
  }
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    cl(v,0);
    for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j)
      scanf(" %c", &g[i][j]);

    int ok = 0;
    for (int i = 0; i < 9 and !ok; ++i) for (int j = 0; j < 9 and !ok; ++j) {
      if (g[i][j] == 'o' and !v[i][j]) {
        s.clear();
        dfs(i, j);
        if (s.size() == 1) ok = 1;
      }
    }

    printf("Case #%d: Can %skill in one move!!!\n", tt, ok?"":"not ");
  }
  return 0;
}
