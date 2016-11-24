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
const int N = 1e5+5;

int t, n, m;
char s[10][10];
vi adji[10][10], adjj[10][10];
int vis[10][10], pari[10][10], parj[10][10];
int si, sj, ei, ej;

int isok(char c) {
  for (int i = 0; i < 8; ++i) if (c == "IEHOVA@#"[i]) return 1;
  return 0;
}

void dfs(int ui, int uj) {
  vis[ui][uj] = 1;
  for (int i = 0; i < (int)adji[ui][uj].size(); ++i) {
    int vi = adji[ui][uj][i], vj = adjj[ui][uj][i];
    if (!vis[vi][vj]) {
      pari[vi][vj] = ui, parj[vi][vj] = uj;
      dfs(vi, vj);
    }
  }
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);

    cl(vis,0);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
      adji[i][j].clear(), adjj[i][j].clear();

    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      if (s[i][j] == '@') si = i, sj = j;
      if (s[i][j] == '#') ei = i, ej = j;

      if (!isok(s[i][j])) continue;
      if (j > 0   and isok(s[i][j-1])) adji[i][j].pb(i),   adjj[i][j].pb(j-1);
      if (j < m-1 and isok(s[i][j+1])) adji[i][j].pb(i),   adjj[i][j].pb(j+1);
      if (i > 0   and isok(s[i-1][j])) adji[i][j].pb(i-1), adjj[i][j].pb(j);
    }

    dfs(si, sj);
    stack<int> q;
    int i = ei, j = ej;
    while (i != si or j != sj) {
      int pi = pari[i][j], pj = parj[i][j];
      if (pari[i][j] > i) q.push(1);
      if (parj[i][j] < j) q.push(2);
      if (parj[i][j] > j) q.push(3);
      int ni = pari[i][j], nj = parj[i][j];
      i = ni, j = nj;
    }

    while (q.size()) {
      int v = q.top(); q.pop();
      printf("%s%c", v!=1?v!=2?"left":"right":"forth", q.size()>0?' ':'\n');
    }
  }
  return 0;
}
