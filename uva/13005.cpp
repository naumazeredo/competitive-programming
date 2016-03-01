#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
const int MAX_N = 1e5;
const int MAX_E = 1e5;

// Dinic's Algorithm
// Source - 0 Sink - n
int src, snk, E;
int fin[MAX_N], pro[MAX_N], dist[MAX_N];
int nex[MAX_E], to[MAX_E], flow[MAX_E], cap[MAX_E];

void init(int n) {
  int i;
  E = src = 0;
  snk = n;
  for (int i = 0; i<=n; ++i) fin[i]=-1;
}

void create_edge(int u, int v, int _cap) {
  to[E]=v; cap[E]=_cap; flow[E]=0;
  nex[E]=fin[u], fin[u]=E++;
}

void add(int u, int v, int _cap) {
  //printf("add: %d %d %d\n", u, v, _cap);
  create_edge(u, v, _cap);
  create_edge(v, u, 0);
}

bool bfs() {
  int st, en, i, u, v;
  queue<int> q;
  for (i=0; i<=snk; ++i) dist[i]=-1;
  dist[src]=st=en=0;
  q.push(src);
  while(!q.empty()) {
    u = q.front();
    q.pop();
    for (i=fin[u]; i>=0; i=nex[i]) {
      v=to[i];
      if (flow[i]<cap[i] && dist[v]==-1) {
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
  }
  return dist[snk]!=-1;
}

int dfs(int u, int fl) {
  if (u==snk) return fl;
  for (int &e=pro[u], v, df; e>=0; e=nex[e]) {
    v=to[e];
    if (flow[e]<cap[e] && dist[v] == dist[u]+1) {
      df = dfs(v, min(cap[e]-flow[e], fl));
      if (df>0) {
        flow[e] += df;
        flow[e^1] -= df;
        return df;
      }
    }
  }
  return 0;
}

int dinitz() {
  int i, ret=0, df;
  while (bfs()) {
    for (i = 0; i <= snk; ++i) pro[i] = fin[i];
    while (1) {
      df = dfs(src, INF);
      if (df) ret += df;
      else break;
    }
  }
  return ret;
}

int n, q;
vector<int> ps[111];

int main() {
  while (scanf("%d%d", &n, &q) != EOF) {
    int zero = 1;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      if (x == n) zero = 0;
      ps[i].resize(x);
      for (int j = 0; j < x; ++j) scanf("%d", &ps[i][j]);
    }

    for (int i = 0; i < q; ++i) {
      int b;
      scanf("%d", &b);

      if (b == 0) {
        printf("%c\n", zero?'Y':'N');
        continue;
      }

      init(2*n+1);
      for (int j = 0; j < n; ++j) {
        add(0, j+1, 1);
        for (int k = 0; k < ps[j].size(); ++k) {
          add(j+1, ps[j][k]+n, 1);
        }
      }

      for (int j = 0; j < b; ++j) {
        int x;
        scanf("%d", &x);
        add(n+x, 2*n+1, 1);
      }

      int dn = dinitz();
      printf("%c\n", dn==b?'Y':'N');
    }
  }

  return 0;
}
