#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

int n, v[N][2], ans, mf, m[N][N], dist[N], cap[N], p[N];

int bfs() {
  cl(dist, 63); cl(cap, 0); cl(p, -1);
  queue<int> q;
  q.push(0);
  dist[0] = 0; cap[0] = INF;
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int v = 0; v <= 2*n+1; v++) if (m[u][v] and dist[v] > dist[u]+1) {
      cap[v] = min(cap[u], m[u][v]);
      dist[v] = dist[u]+1; p[v] = u;
      q.push(v);
    }
  }
  return cap[2*n+1];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &v[i][0], &v[i][1]);
  for (int i = 1; i <= n; i++) {
    cl(m,0);
    int k = 0;
    for (int j = 1; j <= n; j++) if (v[j][0] == i or v[j][1] == i) k++;
    for (int j = 1; j <= n; j++) if (j != i) {
      if (v[j][0] != i and v[j][1] != i) m[0][j] = m[j][v[j][0]+n] = m[j][v[j][1]+n] = 1;
      m[n+j][2*n+1] = k-1;
      if (v[i][0] == j or v[i][1] == j) m[n+j][2*n+1]--;
    }

    mf = 0;
    int f = 0;
    while (f = bfs()) {
      int v = 2*n+1, u = p[v];
      while (v) {
        m[u][v] -= f; m[v][u] += f;
        v = u, u = p[u];
      }
      mf += f;
    }
    if (mf < n-k-1) ans++;
  }

  printf("%d\n", ans);
  return 0;
}
