#include <bits/stdc++.h>
using namespace std;

int n, t, a, b, c, k;
//int ks[1000005];
set<int> ks;

vector<pair<int, int> > adj[200000];
int vis[200000];
int f[200000];

map<pair<int, int>, long long> sumcache;

long long dfs(int u, int o, int d, long long cost) {
  pair<int, int> p (o, u);
  if (sumcache.find(p) == sumcache.end()) {
    sumcache[p] = cost;
    sumcache[make_pair(u, o)] = cost;
  }

  if (u == d) {
    return cost;
  }

  vis[u]=1;
  int s = adj[u].size();
  for (int i = 0; i < s; ++i) {
    int v  = adj[u][i].first;
    int co = adj[u][i].second;

    if (!vis[v]) {
      long long g = dfs(v, o, d, cost + co);
      if (g) return g;
    }
  }

  return 0;
}

int main() {
  cin >> n >> t;
  for (int i = 0; i < n-1; ++i) {
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }

  for (int i = 0; i < t; ++i) {
    memset(f, 0, sizeof(f));
    ks.clear();

    cin >> k;
    for (int j = 0; j < k; ++j) {
      //cin >> ks[j];
      cin >> a;
      if (ks.find(a) == ks.end()) {
        ks.insert(a);
      }
      f[a]++;
    }

    //sort(ks, ks+k);

    long long sum = 0;
    /*
    for (a = 0; a < k-1; ++a) {
      for (b = a + 1; b < k; ++b) {
        if (ks[a]==ks[b]) continue;

        pair<int, int> p (ks[a], ks[b]);
        if (sumcache.find(p) != sumcache.end()) {
          sum += sumcache[p];
          continue;
        }

        pair<int, int> rp (ks[b], ks[a]);
        memset(vis, 0, sizeof(vis));
        sumcache[p] = dfs(ks[a], ks[a], ks[b], 0);
        sumcache[rp] = sumcache[p];
        sum += sumcache[p];
      }
    }
    */
    for (set<int>::iterator x = ks.begin(); x != ks.end(); ++x) {
      for (set<int>::iterator y = next(x); y != ks.end(); ++y) {
        a = *x; b = *y;
        pair<int, int> p (a, b);
        if (sumcache.find(p) != sumcache.end()) {
          sum += sumcache[p] * f[a] * f[b];
          continue;
        }

        pair<int, int> rp (b, a);

        memset(vis, 0, sizeof(vis));
        sumcache[p] = dfs(a, a, b, 0);
        sumcache[rp] = sumcache[p];
        sum += sumcache[p] * f[a] * f[b];
      }
    }

    cout << sum << endl;
  }

  return 0;
}
