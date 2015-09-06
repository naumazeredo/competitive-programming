#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> adj[200];
int d[200];
int c[200];

int main() {
  cin >> n >> m;
  memset(d, 0, sizeof(d));

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    d[a]++;
    d[b]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    c[i] = 1;
    if (d[i] == 1)
      q.push(i);
  }

  int s = -1;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (c[x] % 2 == 0) s++;
    for (int j = 0; j < (int)adj[x].size(); ++j) {
      int v = adj[x][j];
      d[v]--;
      c[v] += c[x];
      if (d[v] == 1)
        q.push(v);
    }
  }

  cout << s << endl;

  return 0;
}
