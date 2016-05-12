#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;

int main() {
  scanf("%d%d", &n, &k);

  if (n/2 > k) { printf("-1\n"); return 0; }
  if (n == 1) { printf("%d\n", k == 0 ? 1 : -1); return 0; }

  printf("%d %d ", k-n/2+1, (k-n/2+1)*2);

  int b = 2e8+1;
  for (int i = 1; i < n/2; ++i) printf("%d %d ", b, b+1), b+=2;
  if (n%2==1) printf("%d", b);
  printf("\n");

  return 0;
}
