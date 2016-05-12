#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b, w;
char c;

typedef pair<int, int> ii;
ii p[100005];
int r[100005];

ii find(int x) {
  if (x == p[x].first)
    return make_pair(x, 0);

  ii f = find(p[x].first);
  p[x] = make_pair(f.first, f.second + p[x].second);
  return p[x];
}

void unite(int x, int y, int w) {
  ii px = find(x),
     py = find(y);
  if (r[px.first] > r[py.first])
    p[py.first] = make_pair(px.first, w + px.second - py.second);
  else {
    p[px.first] = make_pair(py.first, py.second - w - px.second);
    if (r[px.first] == r[py.first])
      r[px.first]++;
  }
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF && n && m) {
    for (int i = 1; i <= n; ++i) {
      p[i] = make_pair(i, 0);
      r[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
      scanf(" %c", &c);
      if (c == '!') {
        scanf("%d%d%d", &a, &b, &w);
        unite(a, b, w);
      } else {
        scanf("%d%d", &a, &b);
        ii pa = find(a),
           pb = find(b);

        if (pa.first != pb.first)
          printf("UNKNOWN\n");
        else
          printf("%d\n", pb.second - pa.second);
      }
    }
  }

  return 0;
}
