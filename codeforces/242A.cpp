#include <bits/stdc++.h>
using namespace std;

int x, y, a, b;

int main() {
  scanf("%d%d%d%d", &x, &y, &a, &b);

  vector<int> ansa, ansb;
  for (int i = a; i <= x; i++)
    for (int j = b; j <= min(i-1, y); j++)
      ansa.push_back(i), ansb.push_back(j);

  printf("%d\n", (int)ansa.size());
  for (int i = 0; i < (int)ansa.size(); i++)
    printf("%d %d\n", ansa[i], ansb[i]);
  return 0;
}
