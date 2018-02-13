#include <bits/stdc++.h>
using namespace std;

int n;
int v[10][10];

int main() {
  scanf("%d", &n);
  while (n--) {
    memset(v, 0, sizeof v);

    for (int i = 1; i <= 9; i += 2)
      for (int j = 1; j <= i; j += 2)
        scanf("%d", &v[i][j]);

    for (int i = 1; i <= 7; i+=2)
      v[9][i+1] = (v[7][i] - v[9][i] - v[9][i+2])/2;

    for (int i = 8; i > 0; i--)
      for (int j = 1; j <= i; j++)
        v[i][j] = v[i+1][j] + v[i+1][j+1];

    for (int i = 1; i <= 9; i++)
      for (int j = 1; j <= i; j++)
        printf("%d%c", v[i][j], " \n"[j==i]);
  }
  return 0;
}
