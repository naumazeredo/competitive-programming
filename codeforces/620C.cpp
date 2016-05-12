#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int n;
vector<int> a;
set<int> mp;

int main() {
  scanf("%d", &n);
  a.resize(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  vector<int> r;
  for (int i = 0; i < n; ++i) {
    if (mp.find(a[i]) != mp.end()) {
      r.push_back(i);
      mp.clear();
    } else {
      mp.insert(a[i]);
    }
  }

  if (r.size() == 0) { printf("-1\n"); return 0; }

  int last = 0;
  r.back() = n-1;
  printf("%d\n", r.size());
  for (int i = 0; i < r.size(); ++i)
    printf("%d %d\n", last+1, r[i]+1), last = r[i]+1;
  return 0;
}
