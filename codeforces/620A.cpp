#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

#define fi first
#define se second

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int a, b, x, y;

int main() {
  scanf("%d%d%d%d", &a, &b, &x, &y);

  printf("%d\n", max(abs(x-a), abs(y-b)));

  return 0;
}
