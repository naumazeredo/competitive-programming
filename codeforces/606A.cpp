#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int a, b, c, x, y, z;

int main() {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
  int d[3];
  d[0] = a-x; d[1] = b-y; d[2] = c-z;

  a = 0;
  for (int i = 0; i < 3; ++i)
    if (d[i] < 0) a-=d[i];

  b = 0;
  for (int i = 0; i < 3; ++i)
    if (d[i] > 0) b+=d[i]/2;

  if (b - a >= 0) printf("Yes\n");
  else printf("No\n");

  return 0;
}
