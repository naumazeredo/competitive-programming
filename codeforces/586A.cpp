#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  scanf("%d", &n);

  int x = 0;
  int l = -5;

  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a) {
      if (i-l!=2) x++;
      else x+=2;
      l = i;
    }
  }

  printf("%d\n", x);
  return 0;
}
