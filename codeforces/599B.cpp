#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n, m;
int f[100005], b[100005];
int p[100005], a[100005];
int imp = 0, amb = 0;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &f[i]);
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);

  for (int i = 1; i <= n; ++i) {
    if (!p[f[i]]) p[f[i]] = i;
    else p[f[i]] = -1;
  }

  for (int i = 1; i <= m; ++i) {
    a[i] = p[b[i]];
    if (a[i] == -1) amb = 1;
    if (a[i] ==  0) imp = 1;
  }

  if (imp) printf("Impossible\n");
  else if (amb) printf("Ambiguity\n");
  else {
    printf("Possible\n");
    for (int i = 1; i <= m; ++i) printf("%d ", a[i]);
    printf("\n");
  }

  return 0;
}
