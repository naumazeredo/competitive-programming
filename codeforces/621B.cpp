#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n;
int g[1005][1005];
int x[300005], y[300005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = 0; i < n; ++i) {
    for (int a = 1; x[i]+a <= 1000 && y[i]+a <= 1000; ++a) g[x[i]+a][y[i]+a]++;
    for (int a = 1; x[i]+a <= 1000 && y[i]-a >= 1; ++a)    g[x[i]+a][y[i]-a]++;
    for (int a = 1; x[i]-a >= 1 && y[i]+a <= 1000; ++a)    g[x[i]-a][y[i]+a]++;
    for (int a = 1; x[i]-a >= 1 && y[i]-a >= 1; --a)       g[x[i]-a][y[i]-a]++;
  }

  ll sum = 0;
  for (int i = 0; i < n; ++i) sum+=g[x[i]][y[i]];

  printf("%lld\n", sum/2);

  return 0;
}
