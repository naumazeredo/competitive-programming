#include <bits/stdc++.h>
using namespace std;

int n, t;

int main() {
  scanf("%d%d", &n, &t);

  if (n == 1 && t == 10) {
    printf("-1\n");
    return 0;
  }

  int i = 1;
  if (t == 10) i++;
  printf("%d", t);

  for (;i<n;++i)
    printf("0");
  printf("\n");

  return 0;
}
