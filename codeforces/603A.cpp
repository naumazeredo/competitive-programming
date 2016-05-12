#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int m[5], w[5], hs, hu;

int main() {
  for (int i = 0; i < 5; ++i) scanf("%d", &m[i]);
  for (int i = 0; i < 5; ++i) scanf("%d", &w[i]);
  scanf("%d%d", &hs, &hu);

  int a = 0;
  for (int i = 0; i < 5; ++i) a += max((i+1)*150, (i+1)*500 - (i+1)*2*m[i] - 50*w[i]);
  a += 100 * hs - 50 * hu;

  printf("%d\n", a);

  return 0;
}
