#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n;
int g[8][8];
int p[8][8];
bitset<32> bm;
int res;

void bt(int u) {
  int a, b;
  int y = u/8, x = u%8;
  while (p[y][x]) u++, y=u/8, x=u%8;

  if (u == 56) {
    if (bm.count() == 28) res++;
    return;
  }

  int pi;
  if (x+1 < 8 and !p[y][x+1]) {
    a = min(g[y][x], g[y][x+1]);
    b = max(g[y][x], g[y][x+1]);
    pi = a*7+b-(a+1)*a/2+1;
    if (!bm[pi]) {
      bm.set(pi);
      p[y][x] = p[y][x+1] = pi;
      bt(u+2);
      p[y][x] = p[y][x+1] = 0;
      bm.reset(pi);
    }
  }

  if (y+1 < 7 and !p[y+1][x]) {
    a = min(g[y][x], g[y+1][x]);
    b = max(g[y][x], g[y+1][x]);
    pi = a*7+b-(a+1)*a/2+1;
    if (!bm[pi]) {
      bm.set(pi);
      p[y][x] = p[y+1][x] = pi;
      bt(u+1);
      p[y][x] = p[y+1][x] = 0;
      bm.reset(pi);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int tt = 1; tt <= n; ++tt) {
    memset(p, 0, sizeof(p));
    for (int i = 0; i < 7; ++i) for (int j = 0; j < 8; ++j) scanf("%d", &g[i][j]);

    res = 0;
    bt(0);
    printf("Teste %d\n%d\n\n", tt, res);
  }
  return 0;
}
