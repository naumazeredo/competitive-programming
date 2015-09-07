#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n, m, x, y, r, s;
vector<pii> adj[4000];
int vis[4000];

int main() {
  memset(vis, 0, sizeof(vis));

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> r;
    adj[x].push_back(make_pair(y, -r));
    adj[y].push_back(make_pair(x, -r));
  }

  cin >> s;

  priority_queue<pipii> q;
  for (int i = 0; i < (int)adj[s].size(); ++i) {
    pii a = adj[s][i];
    q.push(make_pair(a.second, make_pair(s, a.first)));
  }
  vis[s] = 1;

  s = 0;
  while (!q.empty()) {
    pipii u = q.top(); q.pop();
    int v = u.second.second;

    if (vis[v])
      continue;

    for (int i = 0; i < (int)adj[v].size(); ++i) {
      pii a = adj[v][i];
      if (!vis[a.first])
        q.push(make_pair(a.second, make_pair(v, a.first)));
    }

    s -= u.first;
    vis[v] = 1;
  }

  cout << s << endl;

  return 0;
}
