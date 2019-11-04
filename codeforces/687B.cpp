#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, k;

int main() {
  scanf("%d%d", &n, &k);
  int x = 1;
  for (int c, i = 0; i < n; i++) {
    scanf("%d", &c);
    c /= __gcd(x, c);
    int l = __gcd(c, k);
    x *= l;
    k /= l;
  }
  printf("%s\n", k > 1 ? "No" : "Yes");

  return 0;
}
