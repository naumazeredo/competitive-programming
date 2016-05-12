#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int p, d, n;

int e[30][30];

int main() {
  e[0][0] = 1;
  for (int i = 1; i < 21; ++i)
    for (int j = 1; j < 21; ++j)
      e[i][j] = e[i][j-1] + e[i-1][i-j];

  scanf("%d", &p);
  while (p--) {
    scanf("%d%d", &d, &n);
  }
  return 0;
}
