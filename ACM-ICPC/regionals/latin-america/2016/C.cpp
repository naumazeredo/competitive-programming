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
const int N = 1e3+5;

int n, x[N], y[N];
ll c[N][N], ans[N];
map<pii, int> m;

int main() {
  scanf("%d", &n);

  c[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
  }

  for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j)
    m[{ x[i] + x[j], y[i] + y[j] }]++;

  ans[1] = n;
  for (auto v : m)
    for (int i = 1; i <= v.nd; ++i)
      ans[2*i] = (ans[2*i] + c[v.nd][i])%MOD;

  for (int i = 0; i < n; ++i) {
    if (m.find({ 2*x[i], 2*y[i] }) != m.end()) {
      auto v = m[{ 2*x[i], 2*y[i] }];
      for (int j = 1; j <= v; ++j)
        ans[2*j+1] = (ans[2*j+1] + c[v][j])%MOD;
    }
  }

  for (int i = 1; i <= n; ++i) printf("%lld%c", ans[i], i==n?'\n':' ');

  return 0;
}
