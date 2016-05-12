#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;

int n, k;
int a[100005], b[100005];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n/k; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n/k; ++i) scanf("%d", &b[i]);

  int p = 1;
  for (int i = 1; i < k; ++i) p *= 10;

  ll acc = 1;

  for (int i = 0; i < n/k; ++i) {
    ll c;
    if (b[i]) {
      c = (p*10-1)/a[i]+1;
      c -= ((b[i]+1)*p-1)/a[i] - (b[i]*p-1)/a[i];
    } else {
      c = (p*10-1)/a[i] - (p-1)/a[i];
    }
    acc = (acc*c)%mod;
  }

  printf("%lld\n", acc);
  return 0;
}
