#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

const int di[] = { -1,  0, 1, 0 };
const int dj[] = {  0, -1, 0, 1 };

int n, m;
char g[N][N];
int dist[3][N][N], dp[3][3];
int ans;

bool valid(int i, int j) {
  return i < n and i >= 0 and j < m and j >= 0 and g[i][j] != '#';
}

void solv(int v) {
  queue<int> qi, qj;

  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    if (g[i][j] == '1'+v) dist[v][i][j] = 0, qi.push(i), qj.push(j);

  while (qi.size()) {
    int ui = qi.front(); qi.pop();
    int uj = qj.front(); qj.pop();

    for (int k = 0; k < 4; k++) {
      int vi = ui+di[k], vj = uj+dj[k];
      if (valid(vi, vj) and dist[v][vi][vj] > dist[v][ui][uj]+1) {
        dist[v][vi][vj] = dist[v][ui][uj]+1;
        qi.push(vi); qj.push(vj);
      }
    }
  }

  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    if (g[i][j] >= '1' and g[i][j] <= '3' and dist[v][i][j] < INF)
      dp[v][g[i][j]-'1'] = min(dp[v][g[i][j]-'1'], dist[v][i][j] - 1);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", g[i]);
  memset(dp, 63, sizeof dp);
  memset(dist, 63, sizeof dist);

  for (int i = 0; i < 3; i++) solv(i);

  ans = INF;
  ans = min(ans, dp[0][1] + dp[1][2]);
  ans = min(ans, dp[0][1] + dp[0][2]);
  ans = min(ans, dp[1][2] + dp[0][2]);

  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    if (dist[0][i][j] < INF and dist[1][i][j] < INF and dist[2][i][j] < INF)
      ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);

  printf("%d\n", ans==INF?-1:ans);

  return 0;
}
