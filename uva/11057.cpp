#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n;
int a[10005];
int b;

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d", &b);
    sort(a, a+n);

    int u, v;
    int m = 0;
    for (int i = 0; i < n; ++i) {
      int x = lower_bound(a, a+n, b-a[i])-a;
      if (x == i) x++;
      if (i >= x) break;
      if (a[i]+a[x] <= b and (m < a[i]+a[x] or (m == a[i]+a[x] and abs(u-v) > abs(a[i]-a[x])))) {
        u = a[i], v = a[x];
      }
    }

    printf("Peter should buy books whose prices are %d and %d.\n\n", u, v);
  }
  return 0;
}
