#include <bits/stdc++.h>
using namespace std;

const int N = 3000;

int n, a[4][N];
vector<int> v;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++)
      scanf("%d", &a[j][i]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      v.push_back(a[0][i]+a[1][j]);
  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (binary_search(v.begin(), v.end(), -a[2][i]-a[3][j]))
        ans += upper_bound(v.begin(), v.end(), -a[2][i]-a[3][j]) -
               lower_bound(v.begin(), v.end(), -a[2][i]-a[3][j]);

  printf("%d\n", ans);
  return 0;
}
