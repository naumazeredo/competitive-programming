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
const int N = 2e5+5;

const int nm[4][4] = {
  {0, 3, 1, 2},
  {0, 1, 3, 2},
  {2, 1, 3, 0},
  {2, 3, 1, 0}
};

const int nr[4][4] = {
  {1, 0, 0, 3},
  {0, 1, 1, 2},
  {3, 2, 2, 1},
  {2, 3, 3, 0}
};

const int nx[4][4] = {
  {0, 0, 1, 1},
  {0, 1, 1, 0},
  {1, 1, 0, 0},
  {1, 0, 0, 1}
};

const int ny[4][4] = {
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1},
  {1, 1, 0, 0}
};


int n, s, x[N], y[N];
int v[N];
char t[N][50];

void hsort(int l, int r, ld x0, ld y0, ld x1, ld y1, int rot) {
  if (l >= r-1) return;

  ld s2 = (x1-x0)/2;

  vi k[4];
  int ss[4] = {};
  for (int i = l; i < r; i++) {
    int mm = (y[v[i]] > y0+s2+EPS)*2 + (x[v[i]] > x0+s2+EPS);
   // db(i _ v[i] _ x[v[i]] _ y[v[i]] _ mm _ nm[rot][mm]);
    int m = nm[rot][mm];
    k[m].pb(v[i]);
    ss[m]++;
  }

  ss[0] += l; ss[1] += ss[0]; ss[2] += ss[1]; ss[3] += ss[2];

  int p = l;
  for (int i = 0; i < 4; i++) for (int kk : k[i]) v[p++] = kk;

  hsort(l,     ss[0], x0+s2*nx[rot][0], y0+s2*ny[rot][0], x0+s2+s2*nx[rot][0], y0+s2+s2*ny[rot][0], nr[rot][0]);
  hsort(ss[0], ss[1], x0+s2*nx[rot][1], y0+s2*ny[rot][1], x0+s2+s2*nx[rot][1], y0+s2+s2*ny[rot][1], nr[rot][1]);
  hsort(ss[1], ss[2], x0+s2*nx[rot][2], y0+s2*ny[rot][2], x0+s2+s2*nx[rot][2], y0+s2+s2*ny[rot][2], nr[rot][2]);
  hsort(ss[2], r,     x0+s2*nx[rot][3], y0+s2*ny[rot][3], x0+s2+s2*nx[rot][3], y0+s2+s2*ny[rot][3], nr[rot][3]);
}

int main() {
  while (~scanf("%d%d", &n, &s)) {
    for (int i = 0; i < n; i++) scanf("%d%d%s", &x[i], &y[i], t[i]), v[i] = i;
    hsort(0, n, 0, 0, s, s, 0);
    for (int i = 0; i < n; i++) printf("%s\n", t[v[i]]);
  }
  return 0;
}
