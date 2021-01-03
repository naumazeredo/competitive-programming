#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr<<#x<<" == "<<x<<endl
#define _ <<", "<<

int n, m;
int dp[31][3][1<<3];

inline bool has(int b, int j) { return (b & (1<<j)); }

int go(int i, int j, int b) {
  if (~dp[i][j][b]) return dp[i][j][b];
  auto& r = dp[i][j][b];

  if (i == n) return 1;
  if (j == m) return r = go(i+1, 0, b);

  if (has(b, j))
    return r = go(i, j+1, b & (~(1<<j)));

  r = 0;
  if (i < n-1) r += go(i, j+1, b | (1<<j)); // horizontal
  if (j < m-1 and !has(b, j+1))
    r += go(i, j+1, (b & (~(1<<j))) | (1<<(j+1)) );
  return r;
}

int main() {
  m = 3;
  while (~scanf("%d", &n) and n != -1) {
    memset(dp, -1, sizeof(dp));
    printf("%d\n", go(0, 0, 0));
  }
  return 0;
}
