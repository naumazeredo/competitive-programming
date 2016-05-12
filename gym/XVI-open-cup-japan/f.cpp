#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int INF = 2e9;

int n, m, p;
double dp[1005][205];

double vm[205];
vector<iii> adj[205];

int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 0; i < m; ++i) {
    int s, t, d, v;
    scanf("%d%d%d%d", &s, &t, &d, &v);
    s--; t--;
    adj[s].push_back(iii(ii(d, v), t));
    adj[t].push_back(iii(ii(d, v), s));
    vm[s] = max(vm[s], v/(double)d);
    vm[t] = max(vm[t], v/(double)d);
  }

  for (int i = 0; i < 1005; ++i) for (int j = 0; j < 205; ++j) dp[i][j] = -INF;
  dp[0][0] = 0;

  for (int i = 1; i <= p; ++i) {
    for (int j = 0; j < n; ++j) {
      double ma = dp[i-1][j] + vm[j];
      for (int k = 0; k < adj[j].size(); ++k)
        if (i >= adj[j][k].first.first)
          ma = max(ma, dp[i-adj[j][k].first.first][adj[j][k].second] + adj[j][k].first.second);
      dp[i][j] = ma;
    }
  }

  printf("%lf\n", dp[p][0]);

  return 0;
}
