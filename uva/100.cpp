#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

int i, j;

int solve(int x) {
  if (x == 1) return 1;
  if (x%2 == 1) return solve(3*x+1)+1;
  return solve(x/2)+1;
}

int main() {
  while (scanf("%d%d", &i, &j) != EOF) {
    int x = min(i, j), y = max(i, j);
    int m = 0;
    for (int a = x; a <= y; a++)
      m = max(m, solve(a));
    printf("%d %d %d\n", i, j, m);
  }
  return 0;
}
