#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
  scanf("%d%d", &a, &b);
  int c = min(a,b);
  printf("%d %d\n", c, (a-c)/2 + (b-c)/2);
  return 0;
}
