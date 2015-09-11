#include <bits/stdc++.h>
using namespace std;

int n, a, b, tt;
vector<int> adj[600000];
long long t[600000];
int d[600000];
int v[600000];

int main() {
  cin >> n;

  tt = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    d[i] = 0;
    v[i] = 0;
    tt += t[i];
  }

  for (int i = 0; i < n-1; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    d[a]++;
    d[b]++;
  }

  queue<int> q;

  for (int i = 1; i <= n; ++i)
    if (d[i] == 1)
      q.push(i);

  int x, y, s;
  while (!q.empty()) {
    x = q.front(); q.pop();
    v[x] = 1;

    s = adj[x].size();
    for (int i = 0; i < s; ++i) {
      y = adj[x][i];

      if (!v[y]) {
        d[y]--;
        t[y] += t[x];

        if (d[y]==1)
          q.push(y);
      }
    }
  }

  int g = 1;
  for (int i = 1; i <= n; ++i) {
    if (t[i] == tt) {
      g = i;
      break;
    }
  }

  while (true) {
    s = adj[g].size();
    x = -1;
    for (int i = 0; i < s; ++i) {
      y = adj[g][i];
      if (x < 0 || t[y] > t[x])
        x = y;
    }

    t[g] = tt - t[x];

    for (int i = 1; i <= n; ++i)
      cout << t[i] << " ";
    cout << endl;

    if (t[g] >= t[x]) {
      cout << t[g] << endl;
      break;
    } else {
      g = x;
    }
  }

  return 0;
}
