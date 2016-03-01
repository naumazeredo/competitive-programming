#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, m;
int a[2000];

int main() {
  int tt = 1;
  while (scanf("%d", &n) != EOF and n) {
    printf("Case %d:\n", tt++);

    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      int x;
      scanf("%d", &x);
      int sum = INF;
      for (int j = 0; j < n; ++j) for (int k = j+1; k < n; ++k)
        if (abs(a[j]+a[k]-x) < abs(sum-x))
          sum = a[j]+a[k];
      printf("Closest sum to %d is %d.\n", x, sum);
    }
  }
  return 0;
}
