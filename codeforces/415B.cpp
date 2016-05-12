#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a, b;
ll x[100005];

int main() {
  scanf("%d%lld%lld", &n, &a, &b);
  for (int i = 0; i < n; ++i) scanf("%lld", &x[i]);
  for (int i = 0; i < n; ++i) {
    ll p = x[i]*a/b;
    printf("%lld ", x[i] - p*b/a - (p*b%a!=0));
  }
  printf("\n");
  return 0;
}
