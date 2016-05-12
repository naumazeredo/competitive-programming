#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int b[200005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

  ll c = abs(b[0]);
  for (int i = 1; i < n; ++i) c += abs(b[i]-b[i-1]);

  printf("%lld\n", c);

  return 0;
}
