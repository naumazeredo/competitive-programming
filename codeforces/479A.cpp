#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main() {
  scanf("%d%d%d", &a, &b, &c);
  int m = 0;
  m = max(m, a+b+c);
  m = max(m, a*b*c);
  m = max(m, a*b+c);
  m = max(m, a*(b+c));
  m = max(m, a+b*c);
  m = max(m, (a+b)*c);
  printf("%d\n", m);
  return 0;
}
