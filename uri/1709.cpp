#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  scanf("%d", &n);
  int p = 1;
  int c = 0;
  while (1) {
    c++;
    p = (p<=n/2) ? 2*p : 2*p-n-1;
    if (p==1) break;
  }
  printf("%d\n", c);
  return 0;
}
