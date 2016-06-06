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
const int N = 305;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, p, g[N][N], dist[N][N];
vector<int> cx[N*N], cy[N*N];
int ux, uy, vx, vy;

int main() {
  scanf("%d%d%d", &n, &m, &p);

  cl(dist,63);
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
    scanf("%d", &g[i][j]);
    cx[g[i][j]].pb(j);
    cy[g[i][j]].pb(i);

    if (g[i][j]==1) dist[i][j] = i+j-2;
  }

  for (int c = 1; c<p; ++c) {
    if (cx[c].size() * cx[c+1].size() < n*m) {
      for (int i = 0; i < cx[c].size(); ++i) for (int j = 0; j < cx[c+1].size(); ++j) {
        int sx = cx[c][i], sy = cy[c][i],
        dx = cx[c+1][j], dy = cy[c+1][j];
        dist[dy][dx] = min(dist[dy][dx], dist[sy][sx]+abs(dx-sx)+abs(dy-sy));
      }
    } else {
      vector<int> v;
      for (int i = 0; i < cx[c].size(); ++i) v.pb(i);
      sort(v.begin(), v.end(), [=](int a, int b) {
        int ax = cx[c][a], ay = cy[c][a],
        bx = cx[c][b], by = cy[c][b];
        return dist[ay][ax] < dist[by][bx];
      });
      int pnt = 1;

      int bfsdist[N][N];
      cl(bfsdist,63);

      queue<int> qx, qy;
      ux = cx[c][v[0]], uy = cy[c][v[0]];
      bfsdist[uy][ux] = dist[uy][ux];
      qx.push(ux), qy.push(uy);

      while (!qx.empty()) {
        ux = qx.front(); qx.pop();
        uy = qy.front(); qy.pop();

        while (pnt < v.size()) {
          vx = cx[c][v[pnt]], vy = cy[c][v[pnt]];
          if (bfsdist[uy][ux] < dist[vy][vx]) break;
          if (dist[vy][vx] < bfsdist[vy][vx])
            bfsdist[vy][vx] = dist[vy][vx], qx.push(vx), qy.push(vy);
          pnt++;
        }

        for (int i = 0; i < 4; ++i) {
          int nx = ux + dx[i], ny = uy + dy[i];
          if (nx <= 0 or ny <= 0 or nx > m or ny > n) continue;

          if (bfsdist[ny][nx] > bfsdist[uy][ux]+1)
            bfsdist[ny][nx] = bfsdist[uy][ux]+1, qx.push(nx), qy.push(ny);
        }
      }

      for (int i = 0; i < cx[c+1].size(); ++i)
        ux = cx[c+1][i], uy = cy[c+1][i], dist[uy][ux] = bfsdist[uy][ux];
    }
  }

  printf("%d\n", dist[cy[p][0]][cx[p][0]]);

  return 0;
}
