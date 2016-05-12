#include <bits/stdc++.h>
using namespace std;

int x;
int main() {
  scanf("%d", &x);
  int sum = 0;
  while (x) {
    sum += x&1;
    x/=2;
  }
  printf("%d\n", sum);
  return 0;
}
