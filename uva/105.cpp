#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int fi, la;
int l, r, h;
int hs[10005];

vector<int> resl, resr, resh;

int main() {
  fi = INF;
  la = 0;
  while (scanf("%d%d%d", &l, &h, &r) != EOF) {
    fi = min(fi, l);
    la = max(la, r);
    for (int i = l; i < r; ++i) hs[i] = max(hs[i], h);
  }

  printf("%d %d", fi, hs[fi]);

  int h = hs[fi];
  for (int i = fi; i <= la+1; ++i) {
    if (hs[i] == h) continue;
    printf(" %d %d", i, hs[i]);
    h = hs[i];
  }

  printf("\n");

  return 0;
}
