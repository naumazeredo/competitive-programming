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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e3+10;

vi adj[4*N*N];
int dist[4*N*N];

int n, m, e[2], mi[2], pe, pm;
char c;

int pos(int i, int j) { return 4*(i*(m+2)+j); }

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
    scanf(" %c", &c);
    int p  = pos(i,j),
        pu = pos(i-1,j),
        pr = pos(i,j+1),
        pd = pos(i+1,j),
        pl = pos(i,j-1);

    if (c == '+' or c == '|' or c == '^' or c == 'R' or c == 'L' or c == 'D') {
      adj[p  ].pb(pu  );
      adj[p+1].pb(pr+1);
      adj[p+2].pb(pd+2);
      adj[p+3].pb(pl+3);
    }
    if (c == '+' or c == '|' or c == 'v' or c == 'R' or c == 'L' or c == 'U') {
      adj[p  ].pb(pd  );
      adj[p+1].pb(pl+1);
      adj[p+2].pb(pu+2);
      adj[p+3].pb(pr+3);
    }
    if (c == '+' or c == '-' or c == '>' or c == 'D' or c == 'L' or c == 'U') {
      adj[p  ].pb(pr  );
      adj[p+1].pb(pd+1);
      adj[p+2].pb(pl+2);
      adj[p+3].pb(pu+3);
    }
    if (c == '+' or c == '-' or c == '<' or c == 'D' or c == 'R' or c == 'U') {
      adj[p  ].pb(pl  );
      adj[p+1].pb(pu+1);
      adj[p+2].pb(pr+2);
      adj[p+3].pb(pd+3);
    }
  }

  scanf("%d%d%d%d", &e[0], &e[1], &mi[0], &mi[1]);
  pe = pos(e[0], e[1]), pm = pos(mi[0], mi[1]);

  for (int i = pos(1,1); i <= pos(n,m); ++i) {
    vi nv;
    for (int v : adj[i]) {
      int ok = 0;
      for (int x : adj[v]) if (x == i) ok=1;
      if (ok) nv.pb(v);
    }
    nv.pb(i/4*4+((i+1)%4));
    adj[i].clear();
    for (int v : nv) adj[i].pb(v);
  }

  cl(dist, 63);
  queue<int> q;
  q.push(pe);
  dist[pe] = 0;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
      if (dist[v] > dist[u]+1)
      dist[v] = dist[u]+1, q.push(v);
    }
  }

  /*
  int u = pm;
  while (~u) printf("(%d, %d) -> ", u/4%m, u/4/m), u=par[u];
  printf("\n");
  */

  //db(pm _ dist[pm] _ dist[pm+1] _ dist[pm+2] _ dist[pm+3]);
  int mind = min(min(dist[pm], dist[pm+1]), min(dist[pm+2], dist[pm+3]));
  printf("%d\n", mind!=INF?mind:-1);

  return 0;
}
