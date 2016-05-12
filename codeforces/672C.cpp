#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
int a[2], b[2], t[2];
int x[N], y[N];
double d[N];

double d0[N], d1[N];
int p0[N], p1[N], p2[N];

int main() {
  scanf("%d%d%d%d%d%d", &a[0], &a[1], &b[0], &b[1], &t[0], &t[1]);
  scanf("%d", &n);
  double td = 0;
  for (int i = 0; i < n; ++i) {
    p0[i] = p1[i] = p2[i] = i;
    scanf("%d%d", &x[i], &y[i]);

    ll dx = x[i] - t[0], dy = y[i] - t[1];
    d[i] = sqrt(dx*dx + dy*dy);

    td += d[i];

    dx = x[i] - a[0], dy = y[i] - a[1];
    d0[i] = sqrt(dx*dx + dy*dy);

    dx = x[i] - b[0], dy = y[i] - b[1];
    d1[i] = sqrt(dx*dx + dy*dy);
  }

  sort(p0, p0+n, [](int u, int v) { return d[u]-d0[u] > d[v]-d0[v]; });
  sort(p1, p1+n, [](int u, int v) { return d[u]-d1[u] > d[v]-d1[v]; });

  double res = d0[0]+2*td-d[0];
  for (int i = 0; i < n; ++i) {
    res = min(res, d0[i]+2*td-d[i]);
    res = min(res, d1[i]+2*td-d[i]);
  }

  if (n > 1) {
    if (p0[0] == p1[0]) {
      res = min(res, d0[p0[0]] + d1[p1[1]] + 2*td - d[p0[0]] - d[p1[1]]);
      res = min(res, d0[p0[1]] + d1[p1[0]] + 2*td - d[p0[1]] - d[p1[0]]);
    } else {
      res = min(res, d0[p0[0]] + d1[p1[0]] + 2*td - d[p0[0]] - d[p1[0]]);
    }
  }

  printf("%lf\n", res);

  return 0;
}
