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

int n, a, b, c[N], p[N], sz[N], vis[N], h[N], f;
vi oadj[N], adj[N];

int find(int a) { return p[a] == a ? a : p[a] = find(p[a]); }
void unite(int a, int b) {
  if ((a=find(a)) == (b=find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  p[b] = a;
  sz[a]+=sz[b];
}

int far(int u) {
  vis[u] = 1;
  if (h[f] < h[u]) f = u;
  for (int v : adj[u]) if (!vis[v])
    h[v]=h[u]+1, far(v);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]), p[i] = i, sz[i] = 1;
  for (int i = 0; i < n-1; ++i) {
    scanf("%d%d", &a, &b);
    oadj[a].pb(b), oadj[b].pb(a);
    if (c[a] == c[b]) unite(a, b);
  }

  for (int i = 1; i <= n; ++i) for (int v : oadj[i])
    if (find(i) != find(v)) adj[find(i)].pb(find(v));

  if (adj[find(1)].empty()) return 0*printf("0\n");

  f = 1;
  far(find(1));

  cl(vis,0); h[f] = 1;
  far(f);

  printf("%d\n", h[f]/2);

  return 0;
}
