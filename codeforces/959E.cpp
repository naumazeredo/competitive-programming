#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, ans;

int main() {
  scanf("%lld", &n);
  for (ll p = 1; n != 1; p *= 2, n = (n+1)/2)
    ans += (n/2)*p;
  printf("%lld\n", ans);
  return 0;
}
