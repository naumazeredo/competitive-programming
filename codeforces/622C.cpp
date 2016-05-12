#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, m, l, r, x;
int a[400005];
int b[400005];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

  memset(b, -1, sizeof(b));

  int x=1, y=2;
  while (y <= n) {
    if (a[x] != a[y]) while (x<y) b[x++]=y;
    y++;
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &l, &r, &x);
    if (a[l] == x) printf("%d\n", b[l]<=r?b[l]:-1);
    else printf("%d\n", l);
  }

  return 0;
}
