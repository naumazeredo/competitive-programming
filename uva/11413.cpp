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
  while (scanf("%d%d", &n, &m) != EOF) {
    int ma = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), ma = max(ma, a[i]);

    int l = ma, r = 1e9;
    while (l<r) {
      int mid = (l+r)/2;

      int cnt = 0, acc = 0;
      for (int x = 0; x < n; ++x) {
        if (acc+a[x] <= mid) acc+=a[x];
        else cnt++, acc=a[x];
      }
      if (acc) cnt++;
      if (cnt <= m) r = mid;
      else l = mid+1;
    }

    printf("%d\n", l);
  }
  return 0;
}
