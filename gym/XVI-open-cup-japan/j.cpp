#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
vector<ii> a;
int c[100005];
int v[100005];

map<int, int> ms[100005];

bool cmp(ii a, ii b) {
  if (c[a.first] == c[b.first]) return c[a.second] <= c[b.second];
  return c[a.first] < c[b.first];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (c[x] > c[y]) swap(x, y);
    a.push_back(ii(x, y));
  }

  sort(a.begin(), a.end(), cmp);

  for (int rep = 0; rep < 2; ++rep) {
  for (int i = 0; i < m; ++i) {
    ii x = a[i];
    ms[x.first][c[x.first]] = v[x.first];

    if (c[x.second] > c[x.first] && v[x.second] <= v[x.first]) {
      map<int, int>::iterator it = ms[x.first].lower_bound(c[x.second]);
      if (it->first == c[x.second]) v[x.second] = it->second;
      else v[x.second] = (--it)->second+1;
      ms[x.first][c[x.second]] = v[x.second];
      ms[x.second][c[x.first]] = v[x.first];
    }
  }
  }

  for (int i = 1; i <= n; ++i) printf("%d: %d\n", i, v[i]);

  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += v[i]+1;

  printf("%d\n", sum);

  return 0;
}
