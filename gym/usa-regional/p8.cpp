#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int p, d;
ll n;

int main() {
  scanf("%d", &p);
  while (p--) {
    scanf("%d%lld", &d, &n);

    ll l = n;
    while (n != 1) {
      if (n&1) n=3*n+1;
      else n=n/2;
      l = max(l, n);
    }

    printf("%d %lld\n", d, l);
  }
  return 0;
}
