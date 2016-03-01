#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

int main() {
  scanf("%lld%lld", &n, &m);

  ll ma = (n-m+1)*(n-m)/2,
     mi = (n%m)*(n/m+1)*(n/m)/2 + (m-n%m)*(n/m)*(n/m-1)/2;

  printf("%lld %lld\n", mi, ma);
  return 0;
}
