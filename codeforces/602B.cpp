#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n;
int a[100005];
int r[100005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  int l = 1;
  int mi = a[0], ma = a[0];
  int s = 0;
  for (int i = 0; i < n; ++i) {
    int c = a[i];
    r[c] = i;

    if (c > ma) {
      ma = c;
      if (ma - mi > 1) s = r[ma-2]+1, mi=ma-1;
    }
    if (c < mi) {
      mi = c;
      if (ma - mi > 1) s = r[mi+2]+1, ma=mi+1;
    }

    l = max(l, i-s+1);
    //printf("%d %d: %d (%d %d)\n", s, i, l, mi, ma);
  }

  printf("%d\n", l);

  return 0;
}
