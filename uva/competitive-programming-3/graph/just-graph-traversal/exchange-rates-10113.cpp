#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<iii> adj[100];
map<string, int> in;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int vis[100];
ii bfs(int o, int d) {
  memset(vis, 0, sizeof(vis));
  queue<iii> q;
  q.push(make_pair(o, make_pair(1,1)));
  vis[o]=1;

  while (!q.empty()) {
    iii n = q.front(); q.pop();
    int u = n.first;
    ii ru = n.second;

    if (u == d) {
      return ru;
    }

    for (int i = 0; i < (int)adj[u].size(); ++i) {
      n = adj[u][i];
      int v = n.first;
      ii rv = n.second;

      if (!vis[v]) {
        vis[v] = 1;
        int g = gcd(ru.second, rv.first);
        int a = ru.first * (rv.first / g);
        int b = rv.second * (ru.second / g);
        g = gcd(a, b);
        q.push(make_pair(v, make_pair(a/g, b/g)));
      }
    }
  }

  return make_pair(0, 0);
}

int cnt = 0;
string str;
int main() {
  while (1) {
    cin >> str;
    if (cin.eof()) break;

    if (str.compare(".") == 0) break;
    if (str.compare("!") == 0) {
      int x, y;
      int inx, iny;
      string u, v;
      cin >> x >> u >> str >> y >> v;

      if (in.find(u) == in.end())
        in[u] = cnt++;
      if (in.find(v) == in.end())
        in[v] = cnt++;
      inx = in[u];
      iny = in[v];

      int g = gcd(x, y);
      adj[inx].push_back(make_pair(iny, make_pair(x/g, y/g)));
      adj[iny].push_back(make_pair(inx, make_pair(y/g, x/g)));
    } else {
      int inx, iny;
      string u, v;
      cin >> u >> str >> v;

      if (in.find(u) == in.end())
        in[u] = cnt++;
      if (in.find(v) == in.end())
        in[v] = cnt++;
      inx = in[u];
      iny = in[v];

      ii r = bfs(inx, iny);
      if (r.first != 0 && r.second != 0) {
        cout << r.first << " " << u << " = " << r.second << " " << v << endl;
      } else {
        cout << "? " << u << " = ? " << v << endl;
      }
    }
  }

  return 0;
}
