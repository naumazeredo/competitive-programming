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
  #define db(x)
  #define dbs(x)
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

int n, m, k, si, sj, di, dj, dist[N][N];
char g[N][N];
int s[N][N][4];
queue<int> qi, qj;

// Fenwick Tree 2D / Binary Indexed Tree 2D
int bit[N][N];

void add(int i, int j, int v) {
  i+=2, j+=2;
  for (; i < N; i+=i&-i)
    for (int jj = j; jj < N; jj+=jj&-jj)
      bit[i][jj] += v;
}

int query(int i, int j) {
  i+=2, j+=2;
  int res = 0;
  for (; i; i-=i&-i)
    for (int jj = j; jj; jj-=jj&-jj)
      res += bit[i][jj];
  return res;
}

// Whole BIT 2D set to 1
void init() {
  cl(bit,0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == '.')
        add(i, j, 1);
}

// Return number of positions set
int query(int imin, int jmin, int imax, int jmax) {
  return query(imax, jmax) - query(imax, jmin-1) - query(imin-1, jmax) + query(imin-1, jmin-1);
}

// Find all positions inside rect (imin, jmin), (imax, jmax) where position is set
void proc(int imin, int jmin, int imax, int jmax, int v, int tot) {
  if (tot < 0) tot = query(imin, jmin, imax, jmax);
  if (!tot) return;

  int imid = (imin+imax)/2, jmid = (jmin+jmax)/2;
  if (imin != imax) {
    int qnt = query(imin, jmin, imid, jmax);
    if (qnt) proc(imin, jmin, imid, jmax, v, qnt);
    if (tot-qnt) proc(imid+1, jmin, imax, jmax, v, tot-qnt);
  } else if (jmin != jmax) {
    int qnt = query(imin, jmin, imax, jmid);
    if (qnt) proc(imin, jmin, imax, jmid, v, qnt);
    if (tot-qnt) proc(imin, jmid+1, imax, jmax, v, tot-qnt);
  } else {
    // single position set!
    // now process position!!!
    add(imin, jmin, -1);
    qi.push(imin); qj.push(jmin);
    dist[imin][jmin] = v;
  }
}


int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", g[i]);
  scanf("%d%d%d%d", &si, &sj, &di, &dj);
  si--; sj--;
  di--; dj--;

  for (int i = 0; i < n; i++) {
    if (g[i][0] == '.') s[i][0][3] = 1;
    for (int j = 1; j < m; j++)
      s[i][j][3] = (g[i][j] == '.') ? s[i][j-1][3] + 1 : 0;

    if (g[i][m-1] == '.') s[i][m-1][1] = 1;
    for (int j = m-2; j >= 0; j--)
      s[i][j][1] = (g[i][j] == '.') ? s[i][j+1][1] + 1 : 0;
  }

  for (int j = 0; j < m; j++) {
    if (g[0][j] == '.') s[0][j][0] = 1;
    for (int i = 1; i < n; i++)
      s[i][j][0] = (g[i][j] == '.') ? s[i-1][j][0] + 1 : 0;

    if (g[n-1][j] == '.') s[n-1][j][2] = 1;
    for (int i = n-2; i >= 0; i--)
      s[i][j][2] = (g[i][j] == '.') ? s[i+1][j][2] + 1 : 0;
  }

  //for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) db(i _ j _ s[i][j][0] _ s[i][j][1] _ s[i][j][2] _ s[i][j][3]);

  init();

  cl(dist, 63);
  dist[si][sj] = 0;
  add(si, sj, -1);
  qi.push(si); qj.push(sj);

  while (qi.size()) {
    int ui = qi.front(); qi.pop();
    int uj = qj.front(); qj.pop();
    int d = dist[ui][uj];

    if (ui == di and uj == dj) break;

    auto& rs = s[ui][uj];
    proc(ui - min(rs[0]-1, k), uj, ui + min(rs[2]-1, k), uj, d+1, -1);
    proc(ui, uj - min(rs[3]-1, k), ui, uj + min(rs[1]-1, k), d+1, -1);
  }

  printf("%d\n", dist[di][dj] == INF ? -1 : dist[di][dj]);

  return 0;
}
