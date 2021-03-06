#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, x, y;
char a[300];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf(" %c", &a[i]);

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    x = 0; y = 0;
    for (int j = i; j < n; ++j) {
      if (a[j] == 'U') y++;
      if (a[j] == 'D') y--;
      if (a[j] == 'R') x++;
      if (a[j] == 'L') x--;
      if (!x and !y) cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
