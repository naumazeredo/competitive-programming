#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
  scanf("%d%d", &x, &y);
  printf("%d\n", y/(y-x) + (y%(y-x) != 0));
  return 0;
}
