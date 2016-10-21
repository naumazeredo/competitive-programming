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
typedef pair<ll, pii> plii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 5e2+5;

int r, c, n, ev[N][N], er[N][N], ec[N][N], pi[10], pj[10];
int bit[N][N];
//set<piii> q;
priority_queue<piii> q;

void add(int i, int j, int v) {
  for (; i < N; i+=i&-i)
    for (int jj = j; jj < N; jj+=jj&-jj)
      bit[i][jj] += v;
}

void init() {
  cl(bit,0);
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j)
      add(i, j, 1);
}

int query(int i, int j) {
  int res = 0;
  for (; i; i-=i&-i)
    for (int jj = j; jj; jj-=jj&-jj)
      res += bit[i][jj];
  return res;
}

int query(int imin, int jmin, int imax, int jmax) {
  return query(imax, jmax) - query(imax, jmin-1) - query(imin-1, jmax) + query(imin-1, jmin-1);
}

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
    //q.insert({ v+ev[imin][jmin], { imin, jmin } });
    q.push({ -v-ev[imin][jmin], { imin, jmin } });
    add(imin, jmin, -1);
  }
}

int dijkstra(int si, int sj, int di, int dj) {
  if (si == di and sj == dj) return 0;

  init();
  add(si, sj, -1);

  /*
  q.clear();
  q.insert({ ev[si][sj], { si, sj } });
  */
  while (q.size()) q.pop();
  q.push({ -ev[si][sj], { si, sj } });

  while (q.size()) {
    /*
    int ui = q.begin()->nd.st;
    int uj = q.begin()->nd.nd;
    int uc = q.begin()->st;
    q.erase(q.begin());
    */
    int ui = q.top().nd.st;
    int uj = q.top().nd.nd;
    int uc = -q.top().st;
    q.pop();

    if (abs(ui-di) <= er[ui][uj] and abs(uj-dj) <= ec[ui][uj]) return uc;

    int cr = er[ui][uj], cc = ec[ui][uj];
    proc(max(1, ui-cr), max(1, uj-cc),
         min(r,ui+cr), min(c,uj+cc), uc, -1);
  }

  return -1;
}

int main() {
  while (~scanf("%d%d%d", &r, &c, &n)) {
    for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) scanf("%d", &ev[i][j]);
    for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) scanf("%d", &er[i][j]);
    for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) scanf("%d", &ec[i][j]);
    for (int i = 0; i < n; ++i) scanf("%d%d", &pi[i], &pj[i]);

    for (int k = 0; k < n-1; ++k)
      printf("%d%c", dijkstra(pi[k], pj[k], pi[k+1], pj[k+1]), k<n-2?' ':'\n');
  }
  return 0;
}
