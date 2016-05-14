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
typedef pair<ld, ld> pld;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 2e5+5;

int n, k, t[N];
ld f[N], g[N], h[N];
ld dp[N][60];

int nh, pos;
pld hull[N];

bool check(pld a, pld b, pld c) { return (a.st - b.st) * (c.nd - a.nd) < (a.st - c.st) * (b.nd - a.nd); }
void update(pld l) {
  while (nh >= 2 and !check(hull[nh-2], hull[nh-1], l)) if (pos == --nh) --pos;
  hull[nh++] = l;
}

ld eval(int id, ld x) { return hull[id].st + hull[id].nd * x; }
ld query(ld x) {
  while (pos+1 < nh and eval(pos, x) > eval(pos+1, x)) pos++;
  return eval(pos, x);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", t+i);

  f[0] = t[0], g[0] = 1.0, h[0] = 1.0/t[0];
  for (int i = 1; i < n; ++i) {
    f[i] = f[i-1] + t[i];
    g[i] = g[i-1] + f[i]/t[i];
    h[i] = h[i-1] + 1.0/t[i];
  }

  for (int i = 0; i < n; ++i) dp[i][1] = g[i];

  for (int j = 2; j <= k; ++j) {
    nh = pos = 0;
    for (int i = j-1; i < n; ++i) {
      update(mp(dp[i-1][j-1]-g[i-1]+f[i-1]*h[i-1], -f[i-1]));
      dp[i][j] = g[i] + query(h[i]);
    }
  }

  /*
  for (int i = 0; i < n; ++i) dp[i][1] = g[i];
  for (int j = 2; j <= k; ++j) {
    for (int i = j-1; i < n; ++i) {
      dp[i][j] = 1e20;
      for (int x = 1; x <= i; ++x) {
        dp[i][j] = min(dp[i][j], g[i] + dp[x-1][j-1] - g[x-1] + f[x-1]*h[x-1] - h[i]*f[x-1]);
      }
    }
  }
  */

  printf("%.10lf\n", (double)dp[n-1][k]);

  return 0;
}
