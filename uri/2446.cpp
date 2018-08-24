// @subject: dp, knapsack
// @diff: 1

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5, M = 1e3+5;

int n, m, v[M];
int dp[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d", &v[i]);

  dp[0] = 1;
  for (int j = 0; j < m; j++)
    for (int i = n; i >= v[j]; i--)
      dp[i] |= dp[i-v[j]];

  printf("%c\n", dp[n] ? 'S' : 'N');
  return 0;
}
