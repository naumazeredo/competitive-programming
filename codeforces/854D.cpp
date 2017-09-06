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
const int N = 1e5+5, M = 1e6+5;

int n, m, k, d[N], f[N], t[N], c[N], o[N];
int mi, ma;
int vis[N];
int cc[N], cs[N];

ll tvis, sum;

ll st[4*M];

void update(int p, int l, int r, int x, ll v) {
  if (l == r and l == x) { st[p] = v; return; }
  if (r < x or l > x) return;
  update(2*p, l, (l+r)/2, x, v);
  update(2*p+1, (l+r)/2+1, r, x, v);

  if (!st[2*p]) st[p] = st[2*p+1];
  else if (!st[2*p+1]) st[p] = st[2*p];
  else st[p] = min(st[2*p], st[2*p+1]);
}

ll query(int p, int l, int r, int i, int j) {
  if (l > j or r < i) return 0;
  if (i <= l and r <= j) return st[p];
  ll q0 = query(2*p, l, (l+r)/2, i, j);
  ll q1 = query(2*p+1, (l+r)/2+1, r, i, j);
  if (!q0) return q1;
  if (!q1) return q0;
  return min(q0, q1);
}

int main() {
  cl(cc, 63);

  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) scanf("%d%d%d%d", &d[i], &f[i], &t[i], &c[i]), o[i] = i;
  sort(o,o+m,[](int i, int j){ return d[i] < d[j]; });
  //for (int i = 0; i < m; i++) db(i _ o[i] _ d[o[i]] _ f[o[i]] _ t[o[i]] _ c[o[i]]);

  mi = -1, ma = -1;

  tvis = 0;
  cl(vis,0);
  for (int i = 0; i < m; i++) if (f[o[i]] and !vis[f[o[i]]]) {
    vis[f[o[i]]] = 1;
    if (++tvis == n) { mi = d[o[i]]; break; }
  }

  tvis = 0;
  cl(vis,0);
  for (int i = m-1; i >= 0; i--) if (t[o[i]] and !vis[t[o[i]]]) {
    vis[t[o[i]]] = 1;
    if (++tvis == n) { ma = d[o[i]]; break; }
  }

  //db(mi _ ma);

  if (mi == -1 or ma == -1 or ma - mi <= k) return printf("-1\n"), 0;

  tvis = 0; sum = 0;
  cl(vis,0);
  for (int i = m-1; i >= 0; i--) if (t[o[i]]) {
    if (!vis[t[o[i]]]) {
      vis[t[o[i]]] = 1;
      tvis++;

      cs[t[o[i]]] = c[o[i]];
      sum += c[o[i]];
    } else if (c[o[i]] < cs[t[o[i]]]) {
      sum += c[o[i]] - cs[t[o[i]]];
      cs[t[o[i]]] = c[o[i]];
    }

    if (tvis == n)
      //db(i _ d[o[i]] _ sum),
      update(1, 0, M-1, d[o[i]], sum);
  }

  ll ans = 0x3f3f3f3f3f3f3f3f;
  tvis = 0; sum = 0;
  cl(vis,0);
  for (int i = 0; i < m; i++) if (f[o[i]]) {
    if (!vis[f[o[i]]]) {
      vis[f[o[i]]] = 1;
      tvis++;

      cc[f[o[i]]] = c[o[i]];
      sum += c[o[i]];
    } else if (c[o[i]] < cc[f[o[i]]]) {
      sum += c[o[i]] - cc[f[o[i]]];
      cc[f[o[i]]] = c[o[i]];
    }

    if (tvis == n) {
      ll q = query(1, 0, M-1, d[o[i]]+k+1, M-1);
      //db(i _ d[o[i]] _ sum _ q);
      if (q) ans = min(ans, sum+q);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
