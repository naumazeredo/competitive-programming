#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n, m;
int b[105];
int a[105];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

  for (int i = 0; i < m; ++i)
    for (int j = b[i]; j <= n; ++j)
      if (!a[j]) a[j] = b[i];

  for (int i = 1; i <= n; ++i)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}
