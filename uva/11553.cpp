#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int t, n;
int m[10][10];

int ma;
bitset<10> cols;

void cs(int r, int v) {
  for (int i = 0; i < n; ++i) {
    if (cols[i]) continue;
    if (r == n-1) { ma = min(ma, v+m[r][i]); continue; }

    cols.set(i);
    cs(r+1, v+m[r][i]);
    cols.reset(i);
  }
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &m[i][j]);

    cols.reset();
    ma = INF;
    cs(0, 0);
    printf("%d\n", ma);
  }
  return 0;
}
