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
const int N = 4e5+5;

int n, q, p[N], t[N], v, cnt, tin[N], tout[N];
char s[5];
vector<int> adj[N];

int st[4*N], lz[4*N];

void build(int p, int l, int r) {
  if (l == r) { st[p] = t[l]; return; }
  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);
  st[p] = st[2*p] + st[2*p+1];
}

void push(int p, int l, int r) {
  if (lz[p]) {
    st[p] = (r-l+1)-st[p];
    if (l<r) lz[2*p] ^= 1, lz[2*p+1] ^= 1;
    lz[p] = 0;
  }
}

void update(int p, int l, int r, int i, int j) {
  push(p, l, r);
  if (l > j or r < i) return;
  if (i <= l and r <= j) {
    lz[p] ^= 1; push(p, l, r);
    return;
  }

  int m = (l+r)/2;
  update(2*p, l, m, i, j);
  update(2*p+1, m+1, r, i, j);
  st[p] = st[2*p] + st[2*p+1];
}

int query(int p, int l, int r, int i, int j) {
  push(p, l, r);
  if (l > j or r < i) return 0;
  if (i <= l and r <= j) return st[p];
  int m = (l+r)/2;
  return query(2*p, l, m, i, j) + query(2*p+1, m+1, r, i, j);
}

void dfs(int u) {
  tin[u] = ++cnt;
  for (int v : adj[u]) dfs(v);
  tout[u] = cnt;

}

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) scanf("%d", &p[i]), adj[p[i]].pb(i);
  dfs(1);
  for (int i = 1; i <= n; i++) scanf("%d", &t[tin[i]]);

  build(1, 1, n);

  /*
  for (int i = 1; i <= n; i++)
    db(i _ tin[i] _ tout[i] _ query(1, 1, n, tin[i], tin[i]));

  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      db(i _ j _ query(1, 1, n, i, j));
  */

  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%s%d", s, &v);
    if (s[0] == 'g') printf("%d\n", query(1, 1, n, tin[v], tout[v]));
    else update(1, 1, n, tin[v], tout[v]);
  }

  return 0;
}
