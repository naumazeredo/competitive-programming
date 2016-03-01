#include <bits/stdc++.h>

typedef long long ll;

ll l, r;

int main() {
  scanf("%lld%lld", &l, &r);
  if (r-l+1 < 3 or (r-l+1 == 3 and l%2)) { printf("-1\n"); return 0; }
  printf("%lld %lld %lld\n", l+l%2, l+l%2+1, l+l%2+2);
  return 0;
}
