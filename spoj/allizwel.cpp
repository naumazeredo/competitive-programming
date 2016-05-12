#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

const char* s = "ALLIZZWELL";

int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

int t, r, c;
char g[200][200];
int v[200][200];
int f;

void bt(int y, int x, int p) {
  if (g[y][x] != s[p]) return;
  if (p == strlen(s)-1) { f = 1; return; }

  v[y][x] = 1;
  for (int i = 0; i < 8; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if (nx>=0 and nx<c and ny>= 0 and ny<r and !v[ny][nx])
      bt(ny, nx, p+1);
  }
  v[y][x] = 0;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) scanf("%s", g[i]);

    memset(v, 0, sizeof(v));
    f = 0;
    for (int y = 0; y < r; ++y) for (int x = 0; x < c; ++x) bt(y, x, 0);
    printf("%s\n", f?"YES":"NO");
  }
  return 0;
}
