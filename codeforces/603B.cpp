#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n, k;
int s[100005];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
  int d = 2*k-n;

  int m = s[n-1];
  for (int i = 0; i < n-k; ++i) m = max(m, s[i]+s[n-d-i-1]);

  printf("%d\n", m);

  return 0;
}
