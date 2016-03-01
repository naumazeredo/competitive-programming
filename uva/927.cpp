#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int c, d, k;
int a[22], deg;

int main() {
  scanf("%d", &c);
  while (c--) {
    scanf("%d", &deg);
    for (int i = 0; i < deg+1; ++i) scanf("%d", &a[i]);
    scanf("%d%d", &d, &k);

    int ind = 1;
    while (d*ind < k) k -= d*ind, ind++;

    ll res = 0;
    ll npot = 1;
    for (int i = 0; i < deg+1; ++i) {
      res += npot*a[i];
      npot *= ind;
    }

    printf("%lld\n", res);
  }
  return 0;
}
