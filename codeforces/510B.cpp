#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

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

int n, m;
char s[100][100];

int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};

int v[100][100];
int dfs(int y, int x, int py, int px) {
  v[y][x] = 1;

  for (int i = 0; i < 4; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if (nx == px and ny == py) continue;
    if (nx >= 0 and nx < m and ny >= 0 and ny < n and
        s[ny][nx] == s[y][x]) {
      if (v[ny][nx]) return 1;
      else if (dfs(ny, nx, y, x)) return 1;
    }
  }

  return 0;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf(" %s", s[i]);

  int yes = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
    if (!v[i][j]) yes = max(yes, dfs(i, j, -1, -1));

  printf("%s\n", yes ? "Yes" : "No");

  return 0;
}
