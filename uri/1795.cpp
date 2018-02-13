#include <bits/stdc++.h>
using namespace std;

int n;
long long pot3[21];

int main() {
  pot3[0] = 1;
  for (int i = 1; i < 21; i++)
    pot3[i] = 3 * pot3[i-1];

  scanf("%d", &n);
  printf("%lld\n", pot3[n]);
  return 0;
}
