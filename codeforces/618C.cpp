#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
ll x[100005], y[100005];

ll dist2(int a, int b) {
  int dx = x[a] - x[b];
  int dy = y[a] - y[b];
  return dx*dx+dy*dy;
}

/*
ll area2(int a, int b) {
  return llabs(x[0]*y[a] + x[a]*y[b] + x[b]*y[0] - x[a]*y[0] - x[b]*y[a] - x[0]*y[b]);
}
*/

ll area2(int a, int b) {
  return llabs(x[0] * (y[a] - y[b]) +
               x[a] * (y[b] - y[0]) +
               x[b] * (y[0] - y[a]));
}

int main() {
  scanf("%d", &n);
  ll mx = LINF;
  int ind = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &x[i], &y[i]);
    if (i != 0 && dist2(0, i) < mx) mx = dist2(0, i), ind = i;
  }
  printf("%d\n", ind);

  ll am = LINF;
  int j = 0;
  for (int i = 1; i < n; ++i) {
    if (am > area2(ind, i) && area2(ind, i) != 0) {
      am = area2(ind, i);
      j = i;
    }
  }
  printf("%lld\n", area2(ind, j));

  printf("%d %d %d\n", 1, ind+1, j+1);

  return 0;
}
