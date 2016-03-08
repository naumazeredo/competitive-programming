#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, a, b;
int m[400][2];
char c;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %c%d%d", &c, &a, &b);
    for (int x = a; x <= b; ++x) m[x][c=='F']++;
  }

  int res = 0;
  for (int i = 0; i <= 366; ++i)
    res = max(res, min(m[i][0], m[i][1]));

  printf("%d\n", 2*res);
  return 0;
}
