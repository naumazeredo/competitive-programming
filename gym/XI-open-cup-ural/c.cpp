#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k;
int a[15];

int main() {
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) scanf("%d", &a[i]);

  vector<int> v;
  for (int i = -10001; i <= 10001; ++i) {
    int x = i;
    for (int j = 0; j < k; ++j) x = abs(x - a[j]);
    if (x <= 1 && x >= -1) v.push_back(i);
  }

  if (v.size() == 0) { printf("0\n"); return 0; }

  vector<int> x, y;
  x.push_back(v[0]); y.push_back(v[0]);
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] == y.back()+1) y.back() = v[i];
    else x.push_back(v[i]), y.push_back(v[i]);
  }

  printf("%zd\n", x.size());
  for (int i = 0; i < x.size(); ++i) printf("%d %d\n", x[i], y[i]);

  return 0;
}
