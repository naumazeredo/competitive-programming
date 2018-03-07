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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6+5;

int n, m, l[N], a[N], h[N];
ll ans[N];

vector<pll> qq[2];
vector<ll> q[N], dist[2];

void dfs(int u, ll d, int id) {
  if (u > n) return;
  d += l[u];
  dist[id].pb(d);
  for (auto x : q[u]) {
    if (h[x] > d) qq[id].pb({ h[x] - d, x });
  }
  dfs(2*u, d, id); dfs(2*u+1, d, id);
}

void calc(int u) {
  if (u > n) return;

  for (int i = 0; i < 2; i++) {
    dist[i].clear();
    dist[i].pb(0); dist[i].pb(LINF);

    qq[i].clear();
    for (auto x : q[u]) qq[i].pb({ h[x], x });

    dfs(2*u+i, 0, i);

    sort(dist[i].begin(), dist[i].end());
    sort(qq[i].begin(), qq[i].end());
  }

  for (int id = 0; id < 2; id++) {
    int p = 0;
    ll sum = 0;
    for (int i = 0; i < dist[id].size(); i++) {
      for (; p < qq[1-id].size() and qq[1-id][p].st < dist[id][i]; p++) {
        int ind = qq[1-id][p].nd;
        ll x = qq[1-id][p].st;
        ans[ind] += x * i - sum;
      }
      sum += dist[id][i];
    }
  }

  calc(2*u); calc(2*u+1);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++) scanf("%d", &l[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a[i], &h[i]);
    q[a[i]].pb(i);
  }

  calc(1);
  for (int i = 0; i < m; i++) printf("%lld\n", ans[i] - h[i]);

  return 0;
}
