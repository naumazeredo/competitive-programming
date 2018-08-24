#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int t, n, v[N];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    printf("Case #%d: ", tt);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    vector<int> a[2];
    for (int i = 0; i < n; i+=2) a[0].push_back(v[i]);
    for (int i = 1; i < n; i+=2) a[1].push_back(v[i]);
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    int p[2] = {};
    vector<int> x;
    for (int i = 0; i < n; i++) x.push_back(a[i&1][p[i&1]++]);
    vector<int> y = x;
    sort(y.begin(), y.end());

    int ok = 1;
    for (int i = 0; i < n and ok; i++) if (x[i] != y[i]) {
      printf("%d\n", i);
      ok = 0;
    }

    if (ok) printf("OK\n");
  }

  return 0;
}
