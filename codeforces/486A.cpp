#include <bits/stdc++.h>

typedef long long ll;

ll n;

int main() {
  scanf("%lld", &n);
  printf("%lld\n", n/2 + (n%2 ? -n : 0));
  return 0;
}
