#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int d[3];

int main() {
  for (int i = 0; i < 3; ++i)
    scanf("%d", &d[i]);

  printf("%d\n", min(d[0]+d[1]+d[2], min(2*(d[0]+d[1]), min(2*(d[0]+d[2]), 2*(d[1]+d[2])))));
  return 0;
}
