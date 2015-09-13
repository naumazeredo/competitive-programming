#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> adj[600000];
long long t[600000];
int d[600000];
int v[600000];
long long tt;

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

  long long k = 1;
  int x, y, s;
  while (!q.empty()) {
    x = q.front(); q.pop();
    v[x] = 1;

    k = max(k, min(t[x], tt-t[x]));

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

  cout << tt - k << endl;

  return 0;
}
